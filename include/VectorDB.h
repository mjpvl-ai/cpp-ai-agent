#ifndef VECTORDB_H
#define VECTORDB_H

#include <vector>
#include <string>
#include <faiss/IndexFlat.h>

class VectorDB {
public:
    VectorDB(int dim);
    void addDocument(const std::string& text);
    std::vector<std::string> search(const std::vector<float>& queryVec, int topK);

private:
    int dimension;
    faiss::IndexFlatL2 index;
    std::vector<std::string> documents;
};

#endif
