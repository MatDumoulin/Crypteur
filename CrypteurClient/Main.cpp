#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string demanderSourceDuTexte();
string prendreTexteAModifier(string choixSource);
string lireTexteDansFichier(string filePath);
string choixAlgorithme();
string veutEncoder();
string veutEnregistrerDansFichier();
void envoyerDansFichier(string texte);



int main()
{
   string choix = "";
   string action = "";
   string texte = "";


   choix = demanderSourceDuTexte();

   texte = prendreTexteAModifier(choix);

   do
   {
      system("cls");
      cout << "Voici votre chaine de caractere : " << endl <<  texte << endl << endl;
      choix = choixAlgorithme();
      action = veutEncoder();

      choix = veutEnregistrerDansFichier();

      if (choix == "o")
         envoyerDansFichier(texte);

      do
      {
         cout << "Voulez-vous commettre une autre action sur cette chaine de caractere? (o/n) " << endl;
         cin >> choix;
      } while (choix != "o" && choix != "n");
      
   } while (choix == "o");

   return 0;
}

string demanderSourceDuTexte()
{
   string choix;
   cout << "Est-ce que le string provient d'un fichier? (o/n)" << endl;
   do
   {
      cin >> choix;
      if (choix != "o" && choix != "n")
         cout << "Erreur dans le caractere entre. Veuillez recommencer." << endl;

   } while (choix != "o" && choix != "n");
   system("cls");

   return choix;
}

string prendreTexteAModifier(string choixSource)
{
   string texte = "";
   string filePath = "";
   // Récuperer la chaine à modifier
   do
   {
      if (choixSource == "o")
      {
         cout << "Veuillez entrer le chemin(path) du fichier : " << endl << endl;
         cin.ignore(cin.rdbuf()->in_avail());
         getline(cin, filePath);
         texte = lireTexteDansFichier(filePath);
      }
      else
      {
         cout << "Veuillez entrer la chaine de caractere que vous voulez modifier : " << endl;
         // Vider le tampon
         cin.ignore(cin.rdbuf()->in_avail());
         getline(cin, texte);
      }

      if (texte == "")
         cout << "Vous devez entrer une chaine de caractere qui n'est pas vide." << endl;
   } while (texte == "");

   return texte;
}

void envoyerDansFichier(string texte)
{
   string filePath = "";
   ofstream Fichier;
   do
   {
      cout << "Veuillez entrer le chemin du fichier dans lequel vous voulez sauvegarder ce texte : ";
      cin.ignore(cin.rdbuf()->in_avail());
      getline(cin, filePath);

      Fichier.open(filePath);
      if (!Fichier.is_open())
         cout << "Ce chemin de fichier n'est pas valide." << endl;
      else
         Fichier << texte;
   } while (!Fichier.is_open());

}
string lireTexteDansFichier(string filePath)
{
   string texte = "";
   ifstream Fichier(filePath);

   if (!Fichier.is_open())
      cout << "Ce path n'est pas valide." << endl;
   else
   {
      string temp = "";
      while (!Fichier.eof())
      {
         if (temp != "")
            texte += "\n";
         getline(Fichier, temp);
         texte += temp;
      }
      Fichier.close();
   }

   return texte;
}

string choixAlgorithme()
{
   string choix = "";
   cout << "Voici la liste des algorithmes que vous pouvez utiliser :" << endl;
   cout << "1- Mirroiter" << endl << "2- Circuler" << endl << "3- Rotationer" << endl << endl;

   // Tant que le choix n'est pas valide, redemande.
   do
   {
      cout << "Veuillez entrer le numero de l'algorithme que vous avez choisi :" << endl;
      cin >> choix;

      if (choix != "1" && choix != "2" && choix != "3")
         cout << "Ce choix n'est pas valide." << endl;
   } while (choix != "1" && choix != "2" && choix != "3");

   system("cls");

   return choix;
}

string veutEncoder() {
   string action = "";
   do
   {
      cout << "Voulez-vous encoder ou decoder?(encoder/decoder)" << endl;
      cin >> action;

      if (action != "encoder" && action != "decoder")
         cout << "Ce choix n'est pas valide" << endl;
   } while (action != "encoder" && action != "decoder");

   return action;
}

string veutEnregistrerDansFichier()
{
   string choix = "";

   // Post traitement //////////////////////////////////////////////////////////////////
   do
   {
      cout << "Voulez-vous envoyer la reponse dans un fichier texte? (o/n)" << endl;
      cin >> choix;

      if (choix != "o" && choix != "n")
         cout << "Ce choix n'est pas valide" << endl;
   } while (choix != "o" && choix != "n");

   return choix;
}