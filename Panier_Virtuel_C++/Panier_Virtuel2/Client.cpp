#include "Client.h"
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "Article.h"
#include "Commande.h"

Client::Client(const std::string& mail, const std::string& n)
    : email(mail), nom(n) {}

void Client::ajouterArticle(const Article& article) {
    panier.push_back(article);
}

std::vector<Article> Client::articlesTriesParPrix() const {
    std::vector<Article> sortedPanier = Commande::panier;
    std::sort(sortedPanier.begin(), sortedPanier.end(), [](const Article& a, const Article& b) {
        return a.getPrix() < b.getPrix();
        });
    return sortedPanier;
}

double Client::montantTotalCommandeAvecRemise(double remise) const {
    double total = 0;
    for (const auto& article : panier) {
        total += article.getPrix();
    }
    return total * (1 - remise);
}

Article Client::articleLePlusCher() const {
    if (Panier.empty()) {
        throw std::runtime_error("Le panier est vide");
    }
    return *std::max_element(panier.begin(), panier.end(), [](const Article& a, const Article& b) {
        return a.getPrix() < b.getPrix();
        });
}

std::vector<Article> Client::articlesDansIntervalleDePrix(double min, double max) const {
    std::vector<Article> articlesInRange;
    for (const auto& article : panier) {
        if (article.getPrix() >= min && article.getPrix() <= max) {
            articlesInRange.push_back(article);
        }
    }
    return articlesInRange;
}

Article Client::infoArticleParReference(const std::string& reference) const {
    auto it = std::find_if(panier.begin(), panier.end(), [&reference](const Article& article) {
        return article.getReference() == reference;
        });

    if (it != panier.end()) {
        return *it;
    }
    else {
        throw std::runtime_error("Article non trouvé avec la référence donnée");
    }
}
