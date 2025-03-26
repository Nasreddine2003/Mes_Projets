#pragma once
#include "Client.h"
#include "Panier.h"

class Commande {
public:
    int numero;
    Client client;
    Panier panier;
    std::string etat;

    Commande(int num, const Client& c, const Panier& p);
    void modifierEtat(const std::string& nouvelEtat);
    void afficherCommande() const;
};