#include <iostream>
#include <vector>
#include "Article.h"
#include "Panier.h"
#include "Client.h"
#include "Commande.h"

int main() {
    // Création des articles
    std::vector<Article> articles = {
        Article("a", 100.0, 20),
        Article("b", 150.0, 20),
        Article("c", 20.0, 20),
        Article("d", 200.0, 20),
        Article("e", 250.0, 20),
        Article("f", 70.0, 20),
        Article("i", 90.0, 20),
        Article("g", 60.0, 20),
        Article("k", 2100.0, 20),
        Article("l", 5200.0, 20),
        Article("m", 2600.0, 20),
        Article("n", 280.0, 20),
        Article("o", 10.0, 20),
        Article("p", 900.0, 20),
        Article("q", 1000.0, 20),
        Article("r", 220.0, 20)
    };

    Client client("marwaneabdelghaffar@gmail.com", "Marwane Abdelghaffar");
    Panier panier;
    Commande commande(1, client, panier);

    int choix;
    do {
        // Affichage du menu
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Ajouter un article au panier" << std::endl;
        std::cout << "2. Modifier la quantite d'un article dans le panier" << std::endl;
        std::cout << "3. Enlever un article du panier" << std::endl;
        std::cout << "4. Vider le panier" << std::endl;
        std::cout << "5. Afficher le contenu du panier" << std::endl;
        std::cout << "6. Afficher les informations de la commande" << std::endl;
        std::cout << "7. Modifier l'etat de la commande" << std::endl;
        std::cout << "0. Quitter" << std::endl;
        std::cout << "Votre choix : ";
        std::cin >> choix;

        // Traitement des choix
        switch (choix) {
        case 1:
            // Ajouter un article au panier
        {
            std::string reference;
            int quantite;
            std::cout << "Veuillez entrer la reference de l'article : ";
            std::cin >> reference;
            std::cout << "Veuillez entrer la quantité : ";
            std::cin >> quantite;

            // Rechercher l'article par sa référence
            Article* article = nullptr;
            for (auto& art : articles) {
                if (art.reference == reference) {
                    article = &art;
                    break;
                }
            }

            if (article != nullptr) {
                panier.ajouterArticle(article, quantite); // Utilisation de la fonction existante
                std::cout << "Article ajouté au panier avec succès !" << std::endl;
            }
            else {
                std::cout << "Article non trouvé." << std::endl;
            }
        }
        break;
        case 2:
            // Modifier la quantité d'un article dans le panier
        {
            std::string reference;
            int nouvelleQuantite;
            std::cout << "Veuillez entrer la reference de l'article : ";
            std::cin >> reference;
            std::cout << "Veuillez entrer la nouvelle quantité : ";
            std::cin >> nouvelleQuantite;

            panier.modifierQuantiteArticle(reference, nouvelleQuantite);
        }
        break;
        case 3:
            // Enlever un article du panier
        {
            std::string reference;
            std::cout << "Veuillez entrer la reference de l'article à enlever : ";
            std::cin >> reference;
            panier.enleverArticle(reference);
            std::cout << "Article enlevé du panier." << std::endl;
        }
        break;
        case 4:
            // Vider le panier
            panier.viderPanier();
            std::cout << "Panier vidé." << std::endl;
            break;
        case 5:
            // Afficher le contenu du panier
            panier.afficherPanier();
            break;
        case 6:
            // Afficher les informations de la commande
            commande.afficherCommande();
            break;
        case 7:
            // Modifier l'état de la commande
        {
            std::string nouvelEtat;
            std::cout << "Veuillez entrer le nouvel état de la commande : ";
            std::cin >> nouvelEtat;
            commande.modifierEtat(nouvelEtat);
            std::cout << "État de la commande modifié." << std::endl;
        }
        break;
        case 0:
            std::cout << "Au revoir !" << std::endl;
            break;
        default:
            std::cout << "Choix invalide. Veuillez choisir une option valide." << std::endl;
            break;
        }
    } while (choix != 0);

    return 0;
}