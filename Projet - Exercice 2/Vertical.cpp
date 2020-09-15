//Nom : Mikael Lagasse
//Date : 2020/09/08
//But :  un programme qui prend comme entrée un nombre de cinq chiffres. 
//		 Le programme vérifie qu'il y a bien 5chiffres dans le nombre. 
//		 Puis il affiche le nombre verticalement, le premier chiffre sur la première ligne, 
//		 le deuxième chiffre sur la deuxième ligne, ainsi de suite.
//
//Note : C'est extremement compliquer comme programme , j'vais l'expliquer du mieux que je peux.
//FR : 		 J'ai aussi decider de toute split dans plusieurs fonctions pour pas toute crammer dans la meme fonction.
//
//FR : Note 2 : J'ai aussi l'impression que le programme marcherais 100x mieux avec un "while" loop pour verifier si les numeros
//FR :		   donner depassent pas INT_MAX/MIN.
//FR :		   Mais bon , ca marche quand meme! Mais je dis sa comme sa.

#include <iostream>

using namespace std;

// KM : Evite la déclaration des variables en dehors des fonctions. Ce n'est pas une bonne technique de programmation
// KM : Mets la première lettre du deuxième mot en majuscule
int input;			//FR : Les 5 numero donner par l'utilisateur.
int copie;			//Je vais l'expliquer quand j'y arriverais.
int reponseinverse;	//Meme chose , c'est pour contrer certains problemes.
int rem;			//FR : Utiliser dans la fonction pour avoir l'inverse d'une chiffre (exemple 123 -> 321)
bool stepone = false;//Pour verifier si une etape a belle et bien ete fait.

/* FR : Ici , on declare les fonctions et le variables dont ils auront de besoins. */

int output(int reponseinverse);
int main();
int reverse(int input);

int main()
{
	// FR : 
	cout << "Inscrire un nombre qui ce situe entre 10000 et 99999 : ";
	cin >> input;	//FR : On recoit les 5 numero entrer par l'utilisateur.
	if (input < INT_MAX && input > INT_MIN)  //Si les numeros ne depassent pas INT_MAX/MIN , on continue.
	{
		// KM : Il manque une |. OU s'exprime avec deux barres ||
		if (input < 10000 | input > 99999)	//FR : Verifier si c'est vraiment 5 chiffres qui ont ete entrer , pas plus , pas moins.
		{
			cout << "\nEntre 10000 et 99999! "<< input << " n'est pas valide. Recommence.\n\n";		//Si ce n'est pas le cas , on recommence le loop.
			// KM : oh de la récursivité sur le main !!!!
			main();		//Back to the main();
		}
		else
		{
			reverse(input);	//Si toute est respecter , on continue.
		}
	}
	else //Si on depasse INT_MAX/MIN , on quitte le programme , sinon ca cree un loop qui finira jamais.
	{
		// KM : Mouais !!! Ce n'est vraiment pas ma préférence en terme de boucle
		exit;	//chow bye.
	}
}

int reverse(int input)
{
	copie = input;		// FR : On cree une copie du chiffre qu'on veux avoir en vertical , car lui d'origine fini par etre "scrap" ,
						//car on le passe dans une fonction qui le met a l'envers pour ensuite etre mis a la vertical.
						
						//FR : Quand on vas l'output , on va partir du chiffre de la droite , donc c'est pour sa qu'on l'inverse.


	while (input != 0 && stepone == false)	//Si input != 0 et que l'etape qui "reverse" le nombre n'a pas été fait , on execute le loop.
	{
		/* C'est ici qu'on prend les nombres un par un et qu'on les met "a l'envers" dans la variable reponseinverse */
		rem = input % 10;
		reponseinverse = reponseinverse * 10 + rem;
		input /= 10;
	}
	stepone = true;		//FR : Pour indiquer que le loop a belle et bien été exécuter.
	output(reponseinverse);		//On va dans la fonction ou on va écrire les chiffres a la verticale.
	return 0;		//On doit retourner 0 pour indiquer que tout c'est bien passer.
}
int output(int reponseinverse)
{
	while (reponseinverse > 0)		//Un loop qui arrete pas tant que les chiffres sont pas tous display a la verticale un par un
	{
		int digit = reponseinverse % 10;	//On store les chiffres un a la fois dans la variable "digit"
		cout << digit << "\n";		//On les output.
		reponseinverse /= 10;		//On enleve les dernier chiffre de "reponseinverse"
	}
	return 0;		//Pour dire que tout c'est bin passer.
}
/*		SOURCES			*/
// KM : Excellent ! Très bien de citer tes sources !!!
//http://cplusplus.com/forum/general/33594/
//https://www.javatpoint.com/cpp-program-to-reverse-number
//
/*		TESTS			*/
//	input = 12345
//	reponseinverse = 54321
//	Donc quand le numero va etre output , 
//	On va commencer de la droite et on va aller vers la gauche , donc c'est pour sa qu'on l'inverse.	
//	digit = 1,2,4,5
//	Donc on devrait voir :  1
//							2
//							3
//							4
//							5
//
//	input = 90554
//	reponseinverse = 45509	
//	digit = 9,0,5,5,4
//	Donc on devrait voir :  9
//							0
//							5
//							5
//							4
