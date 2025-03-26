#include <vector>
#include "Article.h"
class Panier {
private:
    struct ArticleCommande {
        Article* article;
        int quantiteCommandee;

        ArticleCommande(Article* a, int qte) : article(a), quantiteCommandee(qte) {}
    };

    std::vector<ArticleCommande> articlesCommandes;

public:
    void ajouterArticle(Article* article, int quantite);
    void modifierQuantiteArticle(const std::string& reference, int nouvelleQuantite);
    void enleverArticle(const std::string& reference);
    void viderPanier();
    void afficherPanier() const;
    double calculerMontantTotal() const;
    Article* trouverArticleParReference(const std::string& reference) const;
    Article* trouverArticleLePlusCher() const;
    std::vector<Article*> articlesEntre(double min, double max) const;
    void trierArticlesParPrix();
};
