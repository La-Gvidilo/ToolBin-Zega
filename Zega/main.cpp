#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <math.h>
#include <cstdlib>
using namespace std;


/*
Donc voila le ZegaCore, ici le coeur du projet Zega
Le Zega est un appareil qui permet tout un tas de choses
c'est un outil qui est doté d'une certaine intelligence
Bien que cela ne soit pas très puissant, les recherches que j'ai mener et les decouvertes mathématiques en font un objet dangeureux

Dans un premier temps le Zega est une arme mais aussi une défence.

Voici donc la source complète qui detaillera toutes les fonctions


Le Zega est composer d'un Arduino Uno De 32Ko de ROM ainsi qu'un emplacement pour une carte microSD


Le Zega se branche a une interface qui permet son control.
Le Coeur du Zega est a alimenter soit par USB 5volts, soit par Piles salines 4.5volts ou 3Volts
(Faire attention a la position de l'interupteur a glissière si le Uno est un saintsmart, pour les autres
 cartes il est possible que celà ne suffisent pas, certaines demande 9 à 12 volts pour fonctionner bien qu'en usb moins....)


Toutes découvertes peut et doit être integrer au projet Zega



Interface de controle
===========
|--O-O-O--|  Ici c'est les trois LEDS d'affichages c'est peu mais faut faire avec
|---------|
|-1--2--3-|  de 1 à 9 ce sont des touches capacitives
|-4--5--6-|     En tout cas c'est ce qui était prévu
|-7--8--9-|     Je pense que le Zega final aura moins que 9
|---------|
===========

Il faut aussi compter que je dois mettre un slot micro SD qui demande 4 port digit I/O et une alimentation 5v/GND


Je ne sait pas si tout ce que j'ai dit là s'averrera mais dans tout les cas ce projet est privé


Les programmes génétiques sont un ensembles de solution
Je vais construire un Scanner mathématique plutôt inspiré par les GP mais très differents

18h42...
BON VOILA J'AI REUSSIT A REPONDRE A MA QUESTION
"mais quelle direction prendre ?"
En fait c'est simple, j'ai une formule pour générerer des nombres premiers mais le problème c'est qu'elle ne fonctionne pas
a tout les coups ... En  fait y a une grosse marge d'erreur qui fait que si on veut corriger le problème il faut de gros ordinateurs
, de la mémoire, des test heuristique qui sont très rapide mais demande une certaine config car le calcul a plus que 32bits deviens lourd...
Donc si on est au 1 000 000 nombre déjà avec une formule parfaite c'est compliquer mais si en plus il faut un algorithme pour ... corriger... ^^
Voilà ainsi je vais construire cette technologie pour corriger une formule mathématique automatiquement.


-Les pre-requis sont, un fichier contenant les 1000 premiers nombres premiers(PHASE I)
-Un programme qui scan la formule et en fait un codage
-Un programme qui scan le codage et en fait une formule
-Un programme qui execute une formule

Ensuite plus sera possible...

L'idée c'est de faire cette expérience pour la science et ainsi être le premier être humain capable de donner n'importe quel nombre premier.
Je sait bien, beaucoup on essayer avant moi, mais aucuns on commencer sans rien savoir apart programmer pour ensuite aller vers les sciences...
Si je reussit je laisserai toutes mes technologies et la formule de ce projet sous licence libre avec seule obligation de me citer 2 fois par utilisation...
*/

// (x/sqrt(0.733)) * log(abs(cos(tan(0.267*x)))+x)+sin(tan(sqrt(sqrt(0.585*x))))
class dataEntity{
public:
    void init(){
        delta1 = 0.733;
        delta2 = 0.267;
        delta3 = 0.585;
    }

    void calculus(int x){
        y = (x/sqrt(delta1)) * log(abs(int(cos(tan(delta2*x))))+x)+sin(tan(sqrt(sqrt(delta3*x))));
    }

    double get_y(){
        return y;
    }

    void set_delta1(double d1){
        delta1 = d1;
    }

    void set_delta2(double d2){
        delta2 = d2;
    }

    void set_delta3(double d3){
        delta3 = d3;
    }


private:
    double delta1;
    double delta2;
    double delta3;
    double y;
};




//double func1(int x){
//    return (x/sqrt(0.733)) * log(abs(int(cos(tan(0.267*x))))+x)+sin(tan(sqrt(sqrt(0.585*x))));
//}


int main()
{
    //cout << func1(20);
    return 0;
}
