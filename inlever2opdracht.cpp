#include <iostream> //moet er altijd bij
#include <fstream> //nodig voor bestanden
using namespace std;

void tekstOpScherm () { //een kort infoblokje
    cout << "Naam: Nina Schouten" << endl;
    cout << "Studentennummer: 3909409" << endl;
    cout << "Studie: Informatica & Wiskunde" << endl;
    cout << "Opdracht: Opdracht 2" << endl;
} //tekstOpScherm

int inhoud (int lengte, int breedte, int hoogte) {
    return lengte * breedte * hoogte;
} //inhoud

int telop (int x, int y) {
    return (x + y);
} //twee getallen optellen

void breuk (int x1, int x2, int y1, int y2, int & z1, int & z2) {
    z1 = x1 * y2 + x2 * y1;
    z2 = x2 * y2;
} //twee breuken optellen

double machtRekenen(double x, int y) { //x en y laten accepteren
    if(y == 0) { //als exponent 0 is
        return 1.0; //functie retourneert 1, want macht 0 is gelijk aan 1
    }

    double antwoord = 1.0;

    if (y > 0) { //als exponent positief is
        for (int i =  0; i < y; ++i) {
            antwoord *= x;
        }
    }
    else { //als exponent negatief is
        for (int i = 0; i < -y; ++i) {
            antwoord /= x;
        }
    }

    return antwoord; //resultaat retourneren
}

void cijfersApart (int n) { //n laten accepteren
    int aantalCijfers = 0; //variabele voor aantal cijfers

    //bereken het aantal cijfers
    int temp = n; //temp wordt gebruikt om door elk cijfer te lopen door elke
                  //keer weer te delen door 10
    while (temp != 0) {
        temp /= 10;
        ++aantalCijfers; //hier wordt aantal cijfers bijgehouden
    }

    while (n != 0) { //om elk cijfer van n af te drukken, beginnend met het 
                     //laatste cijfer
        int laatsteCijfer = n % 10; //dit geeft heet laatste cijfer
        cout << laatsteCijfer << endl;
        n /= 10; //verwijdert het cijfer
    }

    //het totale aantal cijfers wordt afgedrukt
    cout << "Het aantal cijfers: " << aantalCijfers << endl; 
}


int main () {
    tekstOpScherm ();
    cout << inhoud (10,10,10) << endl; //inhoud uitrekenen

    cout << telop (2, 3) << endl; //getallen optellen

    int z1, z2; //z1 en z2 definiëren
    breuk (3,4,3,4,z1,z2);
    cout << z1 << "/" << z2 << endl; //breuk optellen
    
    double x; //x definiëren
    int y; //y definiëren
    cout << machtRekenen (3,4) << endl; //de macht berekenen

    int getal; //getal definiëren
    cout << "Voor een getal in: "; //gevraagd om getal in te voeren
    cin >> getal; //hier kan je het getal invoeren
    cijfersApart(getal); 

    //bestanden:
    ifstream invoerBestand("invoer.txt"); //het invoerbestand openen

    if (!invoerBestand.is_open()) { 
        cout << "Fout: Het programma is te incapabel om het invoerbestand " <<
        "te openen" << endl; //als het invoerbestand niet succesvol opent
        return 1; //programma stopt
    }

    ofstream uitvoerBestand("uitvoer.txt"); //het bestand wordt geopend voor schrijven

    if (!uitvoerBestand.is_open()) {
        cout << "Fout: Het programma is te incapabel om het uitvoerbestand " <<
        "te openen" << endl; //aks het uitvoerbestand niet succesvol opent
        return 1; //programma stopt
    }

    char ch; //variabele definiëren
    while (invoerBestand.get(ch)) {
        uitvoerBestand.put(ch); //leest inhoud van invoerbestand, en schrijft naar
                                //uitvoerbestand.
    }

    invoerBestand.close(); //bestand wordt gesloten
    uitvoerBestand.close(); //bestand wordt gesloten

    cout << "De bestanden zijn gekopieerd." << endl; //bericht wordt gegeven om te
                                                     //laten zien dat kopieeractie
                                                     //is voltooid

    ifstream invoerBestand()


    return 0;
} //main



/* int main() {
    std::ifstream inputFile("jouw_bestand.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Kon het bestand niet openen.\n";
        return 1;
    }

    int characterCount = 0;
    int lineFeedCount = 0;
    char ch;

    while (inputFile.get(ch)) {
        characterCount++;

        if (ch == '\n') {
            lineFeedCount++;
        }
    }

    std::cout << "Aantal karakters: " << characterCount << std::endl;
    std::cout << "Aantal regelovergangen: " << lineFeedCount << std::endl;

    inputFile.close();

    return 0;
}
*/