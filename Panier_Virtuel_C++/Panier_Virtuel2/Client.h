#include <string>
#include <vector>
#include "Article.h"

class Client {
private:
    std::string email;
    std::string nom;
    std::vector<Article> panier;

public:
    Client(const std::string& mail, const std::string& n);

    void ajouterArticle(const Article& article);
    std::vector<Article> articlesTriesParPrix() const;
    double montantTotalCommandeAvecRemise(double remise) const;
    Article articleLePlusCher() const;
    std::vector<Article> articlesDansIntervalleDePrix(double min, double max) const;
    Article infoArticleParReference(const std::string& reference) const;
};


