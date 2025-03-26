#include <string>

class Article {
public:
    std::string reference;
    double prix;
    int quantiteEnStock;

    Article(const std::string& ref, double pr, int qteStock);
    bool operator==(const Article& other) const;
};
