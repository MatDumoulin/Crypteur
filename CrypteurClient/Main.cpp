#include <iostream>
#include <string>
using namespace std;

string demanderSourceDuTexte();
string prendreTexteAModifier(string choixSource);
string choixAlgorithme();


int main()
{
   string choix = "";
   string action = "";
   string texte = "";


   choix = demanderSourceDuTexte();

   texte = prendreTexteAModifier(choix);

   do
   {
      choix = choixAlgorithme();


      // Encoder ou décoder? ////////////////////////////////////////////////////////////
      do
      {
         cout << "Voulez-vous encoder ou decoder?(encoder/decoder)" << endl;
         cin >> action;

         if (action != "encoder" && action != "decoder")
            cout << "Ce choix n'est pas valide" << endl;
      } while (action != "encoder" && action != "decoder");


      // Envoyer la réponse à la console ////////////////////////////////////////////////////////////////////////////



      // Post traitement //////////////////////////////////////////////////////////////////
      do
      {

         cout << "Voulez-vous envoyer la reponse dans un fichier texte? (o/n)" << endl;
         cin >> choix;

         if (choix != "o" && choix != "n")
            cout << "Ce choix n'est pas valide" << endl;
      } while (choix != "o" && choix != "n");

      do
      {
         cout << "Voulez-vous commettre une autre action sur cette chaine de caractère? (o/n) " << endl;
         cin >> choix;
      } while (choix != "o" && choix != "n");
      
   } while (choix != "n");

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
   // Récuperer la chaine à modifier
   do
   {
      if (choixSource == "o")
      {
         // Code pour ouvrir un fichier texte et le lire. //////////////////////////////////////////////////////
      }
      else
      {
         cout << "Veuillez entrer la chaine de caractere que vous voulez modifier : " << endl;
         cin >> texte;
      }

      if (texte == "")
         cout << "Vous devez entrer une chaine de caractère qui n'est pas vide." << endl;
   } while (texte == "");

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