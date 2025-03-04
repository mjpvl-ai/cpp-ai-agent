#include "llama.h"
#include <vector>
#include <string>
#include <stdexcept>  // Fix missing header for std::runtime_error

class AIClient {
private:
    llama_model *model;
    llama_context *ctx;
    const llama_vocab *vocab;  // Store vocab pointer

public:
    AIClient(const std::string &modelPath) {
        // Initialize model parameters
        llama_model_params model_params = llama_model_default_params();
        model = llama_model_load_from_file(modelPath.c_str(), model_params);
        if (!model) {
            throw std::runtime_error("Failed to load model.");
        }

        // Initialize context parameters
        llama_context_params ctx_params = llama_context_default_params();
        ctx = llama_init_from_model(model, ctx_params);
        if (!ctx) {
            llama_model_free(model);
            throw std::runtime_error("Failed to create context.");
        }

        // Get vocabulary pointer from the model
        vocab = llama_model_get_vocab(model);
    }

    std::string query(const std::string &prompt) {
        std::vector<llama_token> tokens(512);  // Adjust size as needed

        // Tokenize input (now using `vocab` instead of `model`)
        int token_count = llama_tokenize(vocab, prompt.c_str(), prompt.length(), tokens.data(), tokens.size(), true, false);
        if (token_count < 0) {
            throw std::runtime_error("Tokenization failed.");
        }
        tokens.resize(token_count);

        std::string response;
        for (int i = 0; i < tokens.size(); ++i) {
            // Use `llama_eval_tokens` instead of `llama_eval`
            int token = llama_eval_tokens(ctx, &tokens[i], 1);
            if (token == llama_vocab_eos(vocab)) break;  // Use `vocab` instead of `model`

            char piece[64];  // Adjust buffer size if needed
            llama_token_to_piece(vocab, token, piece, sizeof(piece));
            response += piece;
        }
        return response;
    }

    ~AIClient() {
        llama_free(ctx);
        llama_model_free(model);
    }
};
