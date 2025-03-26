#include "Panier.h"
#include "Article.h"
#include <iostream>
#include <algorithm>

void Panier::ajouterArticle(Article* article, int quantite) {
    for (auto& articleCommande : articlesCommandes) {
        if (articleCommande.article == article) {
            articleCommande.quantiteCommandee += quantite;
            return;
        }
    }
    articlesCommandes.emplace_back(article, quantite);
}

void Panier::modifierQuantiteArticle(const std::string& reference, int nouvelleQuantite) {
    for (auto& articleCommande : articlesCommandes) {
        if (articleCommande.article->reference == reference) {
            articleCommande.quantiteCommandee = nouvelleQuantite;
            return;
        }
    }
}

void Panier::enleverArticle(const std::string& reference) {
    articlesCommandes.erase(
        std::remove_if(articlesCommandes.begin(), articlesCommandes.end(),
            [&reference](const ArticleCommande& articleCommande) {
                return articleCommande.article->reference == reference;
            }),
        articlesCommandes.end());
}

void Panier::viderPanier() {
    articlesCommandes.clear();
}

void Panier::afficherPanier() const {
    for (const auto& articleCommande : articlesCommandes) {
        double prixUnitaire = articleCommande.article->prix;
        if (articleCommande.quantiteCommandee > 10) {
            prixUnitaire *= 0.8;
        }
        std::cout << "Référence : " << articleCommande.article->reference
            << ", Quantité : " << articleCommande.quantiteCommandee
            << ", Prix unitaire : " << articleCommande.article->prix
            << ", Prix après remise : " << prixUnitaire
            << ", Prix total : " << articleCommande.quantiteCommandee * prixUnitaire
            << std::endl;
    }
}

double Panier::calculerMontantTotal() const {
    double total = 0.0;
    for (const auto& articleCommande : articlesCommandes) {
        double prixUnitaire = articleCommande.article->prix;
        if (articleCommande.quantiteCommandee > 10) {
            prixUnitaire *= 0.8;
        }
        total += articleCommande.quantiteCommandee * prixUnitaire;
    }
    return total;
}

Article* Panier::trouverArticleParReference(const std::string& reference) const {
    for (const auto& articleCommande : articlesCommandes) {
        if (articleCommande.article->reference == reference) {
            return articleCommande.article;
        }
    }
    return nullptr;
}

Article* Panier::trouverArticleLePlusCher() const {
    if (articlesCommandes.empty()) return nullptr;
    return std::max_element(articlesCommandes.begin(), articlesCommandes.end(),
        [](const ArticleCommande& a, const ArticleCommande& b) {
            return a.article->prix < b.article->prix;
        })->article;
}

std::vector<Article*> Panier::articlesEntre(double min, double max) const {
    std::vector<Article*> resultat;
    for (const auto& articleCommande : articlesCommandes) {
        if (articleCommande.article->prix >= min && articleCommande.article->prix <= max) {
            resultat.push_back(articleCommande.article);
        }
    }
    return resultat;
}

void Panier::trierArticlesParPrix() {
    std::sort(articlesCommandes.begin(), articlesCommandes.end(),
        [](const ArticleCommande& a, const ArticleCommande& b) {
            return a.article->prix < b.article->prix;
        });
}
