#include "VectorDB.h"
#include <iostream>

VectorDB::VectorDB(int dim) : dimension(dim), index(dim) {}

void VectorDB::addDocument(const std::string& text) {
    std::vector<float> embedding(dimension, 0.5f);  // Dummy embedding
    index.add(1, embedding.data());
    documents.push_back(text);
}

std::vector<std::string> VectorDB::search(const std::vector<float>& queryVec, int topK) {
    std::vector<float> distances(topK);
    std::vector<faiss::idx_t> indices(topK);

    index.search(1, queryVec.data(), topK, distances.data(), indices.data());

    std::vector<std::string> results;
    for (int i = 0; i < topK; i++) {
        if (indices[i] >= 0) {
            results.push_back(documents[indices[i]]);
        }
    }
    return results;
}
