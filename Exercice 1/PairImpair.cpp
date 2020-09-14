//Nom : Mikael Lagasse
//Date : 2020/09/08
//But :  un programme qui lit un entier et qui détermine et affiche s’il s’agit d’un entier pair d’un entier impair.

#include <iostream>				//cin et cout , on en aura toujours de besoin de iostream.

using namespace std;			//Parce que écrire std:: c'est tannant.


void main()						//On commence par main.
{
	double input;				//on déclare la variable ou notre input sera conservé (voir #convert pour une explication sur pourquoi j'ai utiliser double et non int)
	int input2;					//J'expliquerais l'utilisation de cette variable un peu plus tard.
	int reponse;				//Ici , c'est avec cette variable qu'on va etre capable de vérifier si le nombre est pair ou non.
	//int reponse2;
	setlocale(LC_ALL, "");		//accents et tout.	//Bon , ici , on regarde si input est un nombre pair ou pas. Si "reponse" est égal à 1 , c'est impair , si c'est égal à 2 , c'est pair.
	while (true)				//Un while loop qui recommence tant qu'on lui donne pas une reponse valide. voir le commentaire #validation pour comprendre les critères.
	{
		cout << "Veuillez me donner un chiffre.\n";
		cin >> input;			//Les chiffres entrer par l'utilisateur seront storer dans la variable input.
		cout << "\n";			//skip une ligne
		if (input > INT_MAX | input < INT_MIN)		//#validation : Verification a savoir si l'utilisateur depasse INT_MIN/MAX.
		{
			cout << "Un chiffre qui ne depasse pas : " << INT_MAX << " ou " << INT_MIN << " .\n";	//Ce message s'affiche si l'utilisateur nous donner un chiffre qui depasse INT_MIN ou INT_MAX , car depasser ses valeurs brise le programme.
			cout << "\n";		//skip une autre ligne.
			exit;				//On relance le loop.
		}
		else
		{
			break;			//Si on donne une reponse qui est valide , on continue.
		}
	}
	input2 = int(input);	//#convert : On converti la reponse de l'utilisateur en Integer , car sinon on ne pourra pas utiliser %.
	reponse = input2 % 2;	//Modulo , parce que c'est sa qui est sa.
	if (reponse == 0)		//Si la reponse est 0 , c'est parce que c'est pair , donc on le dit a l
	{
		cout << input2 << " est un nombre pair!\n";
	}
	else					//Si c'est pas 0 , c'est parce que c'est impair. On l'averti à propos de sa aussi.
	{
		cout << input2 << " est un nombre impair!\n";
	}
}
	//Et on ferme int main() , car on a fini!

	
	
/*					  ***TESTS***						*/
//	input = 5
//	donc 5 % 2 = 1
//	si reponse = 1 , c'est donc impair.
//	donc le programme va output "5 est un nombre impair!"
//
//	input = 4
//	donc 4 % 2 = 0
//	si reponse = 0 , c'est donc pair.
//	donc le programme va output "4 est un nombre pair!"