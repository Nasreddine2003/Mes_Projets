#include "Panier.h"
#include "Commande.h"
#include <iostream>

Commande::Commande(int num, const Client& c, const Panier& p) : numero(num), client(c), panier(p), etat("en attente de traitement") {}

void Commande::modifierEtat(const std::string& nouvelEtat) {
    etat = nouvelEtat;
}

void Commande::afficherCommande() const {
    std::cout << "Numero de commande: " << numero << std::endl;
    std::cout << "Client: " << client.nom << " (" << client.email << ")" << std::endl;
    std::cout << "Etat de la commande: " << etat << std::endl;

}

