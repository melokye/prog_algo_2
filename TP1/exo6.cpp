#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
};

struct DynaTableau{
    int* donnees;
    int taille; // indique la prochaine place disponible
    int capacite;
    // your code
};

void initialise(Liste* liste)
{
    liste->premier = nullptr;
}

bool est_vide(const Liste* liste)
{
    return liste->premier == nullptr;
    // return false;
}

void ajoute(Liste* liste, int valeur)
{
    if(liste->premier == nullptr){
        liste->premier = new Noeud;
        liste->premier->donnee = valeur;
        liste->premier->suivant = nullptr;
    }else{
        Noeud *ptr = liste->premier;
        for (; ptr->suivant != nullptr; ptr = ptr->suivant){}
        ptr->suivant = new Noeud;
        ptr = ptr->suivant;
        ptr->donnee = valeur;
        ptr->suivant = nullptr;
    }
}

void affiche(const Liste* liste)
{
    for (Noeud *ptr = liste->premier; ptr != nullptr; ptr = ptr->suivant)
    {
        std::cout << ptr->donnee << std::endl;
    }
}

int recupere(const Liste* liste, int n)
{
    Noeud *ptr = liste->premier;
    for (int i = 0; i < n ; i++){
        if(ptr == nullptr){
            cout << "index out of range, the index asked is " << n << " but the max is " << i << "\n";
            exit(1);
        }else{
            ptr = ptr->suivant;
        }
    }
    return ptr->donnee;
}

int cherche(const Liste* liste, int valeur)
{
    int i = 0;
    for (Noeud *ptr = liste->premier; ptr != nullptr; ptr = ptr->suivant, i++){
        if(ptr->donnee == valeur){
            return i;
        }
    }
    return -1;
}

void stocke(Liste* liste, int n, int valeur){
    Noeud *ptr = liste->premier;
    int i = 0; 
    while(ptr != nullptr && i < n){
        ptr = ptr->suivant;
        i++;
    }

    if(ptr != nullptr){
        ptr->donnee = valeur;
    }
}

void initialise(DynaTableau* tableau, int capacite)
{
    tableau->donnees = nullptr;
    tableau->taille = 0;
    tableau->capacite = capacite;
}

bool est_vide(const DynaTableau* liste)
{
    return !(liste->taille);
}

void ajoute(DynaTableau* tableau, int valeur)
{
    if(tableau->taille >= tableau->capacite || tableau->donnees == nullptr){
        tableau->capacite += tableau->capacite * (tableau->taille / tableau->capacite);
        tableau->donnees = (int*) realloc(tableau->donnees, sizeof(int) * tableau->capacite); // realloc agit comme un malloc si ptr == null
        if(tableau->donnees == NULL){ // TODO : est-ce que c'est pas mieux de remplacer NULL par nullptr ?
            cout << "Problème rencontré au niveau de l'allocation mémoire...\n";
            exit(1); 
        }
    }
    tableau->donnees[tableau->taille++] = valeur;
}

void affiche(const DynaTableau* tableau)
{
    for (int i = 0; i < tableau->taille; i++)
    {
        cout << tableau->donnees[i] << "\n";
    }
}

int recupere(const DynaTableau* tableau, int n)
{
    if(tableau->taille < n){
        cout << "index out of range, index demandé : " << n << ", index max : " << tableau->taille << "\n";
        exit(1);
    }
    return tableau->donnees[n];
}

int cherche(const DynaTableau* tableau, int valeur)
{
    for(int i = 0; i < tableau->taille; i++){
        if(valeur == tableau->donnees[i])
            return i;
    }
    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    if(tableau->taille < n){
        cout << "erreur, index out of range, index saisi : " << n << ", index max : " << tableau->taille << "\n";
        exit(1);
    }
    tableau->donnees[n] = valeur;
}

void pousse_file(DynaTableau* tableau, int valeur){
    ajoute(tableau, valeur);
}
void pousse_file(Liste* liste, int valeur)
{
    ajoute(liste, valeur);
}

/*
On suppose que le tableau fourni n'est pas vide
*/
int retire_file(DynaTableau* tableau)
{
    int val = tableau->donnees[0];
    for (int i = 1; i < tableau->taille; i++)
    {
        tableau->donnees[i - 1] = tableau->donnees[i];
    }
    tableau->taille--;
    return val;
}

/*
On part du principe que la liste fournie n'est pas vide
*/
int retire_file(Liste* liste)
{
    /*
    if(est_vide(liste)){
        cout << "erreur la liste fournie est vide \n";
        exit(1);
    }
    */
    Noeud* premier = liste->premier;
    liste->premier = liste->premier->suivant;

    int val = premier->donnee;
    delete premier;
    
    return val;
}

void pousse_pile(DynaTableau* tableau, int valeur)
{
    ajoute(tableau, valeur);
}
void pousse_pile(Liste* liste, int valeur)
{
    ajoute(liste, valeur);
}

/*
    On suppose que le tableau fourni n'est pas vide
*/
int retire_pile(DynaTableau* tableau)
{
    int val = tableau->donnees[--(tableau->taille)];
    if(!(tableau->taille)){
        free(tableau->donnees);
        tableau->donnees = nullptr;
    }
     // TODO implémenter un redimensionnement du tableau ? => ajouter un champs bloc ?
    return val;
}

/*
On suppose que la liste fournie n'est pas vide
*/
int retire_pile(Liste* liste)
{
    Noeud* dernier;
    int val;
    if(liste->premier->suivant == nullptr){
        dernier = liste->premier;
        liste->premier = nullptr;
    }else{
        Noeud* avant_der;

        for(avant_der = liste->premier; avant_der->suivant->suivant != nullptr; avant_der = avant_der->suivant){}
        dernier = avant_der->suivant;
        avant_der->suivant = nullptr;
    }
    
    val = dernier->donnee;
    delete dernier;
    return val;
}


int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    cout << "tableau : \n";
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    cout << "tableau : \n";
    affiche(&tableau);
    std::cout << std::endl;

    // Liste pile; 
    // Liste file; 
    // initialise(&pile);
    // initialise(&file);

    DynaTableau pile;
    DynaTableau file;
    const int capacite = 10;
    initialise(&pile, capacite);
    initialise(&file, capacite);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }
    // retire_file(&file);
    
    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }
    // retire_pile(&pile);
    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
