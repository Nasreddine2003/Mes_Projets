#include "Article.h"

Article::Article(const std::string& ref, double pr, int qteStock)
    : reference(ref), prix(pr), quantiteEnStock(qteStock) {}

bool Article::operator==(const Article& other) const {
    return this->reference == other.reference;
}
