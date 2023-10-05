#include <iostream> // Altijd erbij

#include <ctime> // Voor de tijd

using namespace std;

int main() {
    // Informatieblok
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "De makers zijn: " << endl;
    cout << "Nina Schouten: 2005, " <<
        "Wiskunde + Informatica, 3909409" << endl;
    cout << "Simon van Prooijen: 2004, Informatica, 3698033" << endl;
    cout << "Opdracht 1" << endl;
    cout << "Gemaakt op 11-09-2023" << endl;
    cout << "Op de volgende schermen zullen vragen staan " <<
        "die door u beantwoord moeten worden." << endl;
    cout << "Hierdoor kunnen we een uitslag " <<
        "eruit krijgen die u zal vertellen of u wel," << endl;
    cout << "of niet bent toegelaten tot " <<
        "de door u gekozen studie." << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    // De tijd momenteel.
    time_t now = time(0);
    tm * ltm = localtime( & now);

    // De variabelen en epsilon een waarde geven.   
    const int Dag = ltm -> tm_mday;
    const int Maand = 1 + ltm -> tm_mon;
    const int Jaar = 1900 + ltm -> tm_year;
    int GeboorteJaar;
    int GeboorteMaand;
    int GeboorteDag;
    int JaarOud;
    int MaandOud;
    int MaandOudTot;
    int MaandDagen;
    int MaandTeller;
    int DagenTeller;
    int Getal1;
    int Getal2;
    int Getal2Mod10;
    int Gok;
    double Epsilon;
    char WeekDagEnkel;
    char WeekDagDubbel;
    char DagRaad1;
    char DagRaad2;
    char Antwoord;
    string Aanspreek;
    string Aanspreek2;
    string GoedAntwoord;
    Epsilon = 0.1;

    // Het aantal dagen dat de momentele maand bevat.
    if (Maand == 1 || Maand == 3 || Maand == 5 || Maand == 7 || 
        Maand == 8 || Maand == 10 || Maand == 12) {
        MaandDagen = 31;
    } else if (Maand == 4 || Maand == 6 || Maand == 9 || Maand == 11) {
        MaandDagen = 30;
    } else if (Maand == 2 && Jaar % 4 == 0) {
        MaandDagen = 29;
    } else {
        MaandDagen = 28;
    }

    // Hierbij wordt het geboortejaar ingevoerd door de persoon die de
    // vragen beantwoordt.
    cout << "In welk jaar bent u geboren?" << endl;
    cin >> GeboorteJaar;

    // Antwoord als iemand 100% ouder is dan 100 jaar.
    if (GeboorteJaar < Jaar - 101) {
        cout <<
            "Sorry, u bent te oud om mee te doen." << endl;
        return 1;
    }

    // Antwoord als iemand 100% jonger is dan 10 jaar.
    if (Jaar - GeboorteJaar < 10 && GeboorteJaar < Jaar) {
        cout <<
            "Sorry, je bent te jong om mee te doen." << endl;
        return 1;
    }

    // Antwoord als iemand een jaartal in de toekomst invoert.
    if (GeboorteJaar > Jaar) {
        cout <<
            "Deze datum is ongeldig." << endl;
        return 1;
    }

    // De vraag zodat de persoon zijn/haar geboortemaand invoert. 
    cout << "In welke maand bent u geboren?" << endl;
    cin >> GeboorteMaand;

    // Antwoord als iemand een ongeldige maand invoert.
    if (GeboorteMaand < 1 || GeboorteMaand > 12) {
        cout <<
            "Deze datum is ongeldig." << endl;
        return 1;
    }

    // Antwoord als iemand in deze maand al ouder is geworden dan 100.
    if (Jaar - GeboorteJaar == 101 && GeboorteMaand < Maand) {
        cout <<
            "Sorry, u bent te oud om mee te doen." << endl;
        return 1;
    }

    // Antwoord als iemand nog 9 is, en nog niet jarig is geweeest deze
    // maand en dus nog jonger dan 10 is.
    if (Jaar - GeboorteJaar == 10 && GeboorteMaand > Maand) {
        cout <<
            "Sorry, je bent te jong om mee te doen." << endl;
        return 1;
    }

    // Antwoord als de persoon nog te jong is om mee te doen.
    // Niet hetzelfde als de code hieronder, deze is voor te
    // jong i.p.v. ongeldige datum.
    if (Jaar - GeboorteJaar == 0 && GeboorteMaand < Maand) {
        cout <<
            "Sorry, je bent te jong om mee te doen." << endl;
        return 1;
    }

    // Antwoord als de persoon een ongeldige maand invoert, 
    // oftewel, de persoon is nog niet geboren, dus is het een ongeldige
    // datum. Niet dezelfde code als hierboven, die is voor te jong 
    // i.p.v. een ongeldige datum.
    if (Jaar - GeboorteJaar == 0 && GeboorteMaand > Maand) {
        cout <<
            "Deze datum is ongeldig." << endl;
        return 1;
    }

    // De vraag zodat de persoon zijn/haar geboortedag invoert.
    cout << "Op welke dag bent u geboren?" << endl;
    cin >> GeboorteDag;

    // Antwoord als iemand een ongeldige dag invoert. 
    // In januari zou dat bijvoorbeeld 40 januari zijn.
    if (GeboorteDag < 1 || GeboorteDag > MaandDagen) {
        cout <<
            "Deze datum is ongeldig." << endl;
        return 1;
    }

    // Antwoord als iemand in een van de dagen van deze maand al jarig is 
    // geweest, en dus nu ouder dan 100 jaar. Dit komt dus door de dag. 
    if (Jaar - GeboorteJaar == 101 && 
        Maand == GeboorteMaand && GeboorteDag < Dag) {
        cout <<
            "Sorry, u bent te oud om mee te doen." << endl;
        return 1;
    }

    // Antwoord als iemand in een van de dagen van deze maand nog jarig
    // moet worden, en dat dus nog niet is geweest. Hierdoor is de
    // persoon nog te jong om mee te doen, omdat hij/zij jonger is dan 10.
    if (Jaar - GeboorteJaar == 10 && 
    GeboorteMaand == Maand && GeboorteDag > Dag) {
        cout <<
            "Sorry, je bent te jong om mee te doen." << endl;
        return 1;
    }

    // Antwoord als de persoon in een van de dagen van de maand jarig is
    // maar nog niet is geweest, dus nog steeds 9 is. Hierdoor is de 
    // persoon te jong nog om mee te doen. Wordt dus gemeten door de dag. 
    // Niet dezelfde code als hieronder, dit is voor te jong i.p.v. 
    // ongeldige datum.
    if (Jaar - GeboorteJaar == 0 && 
        GeboorteMaand == Maand && GeboorteDag <= Dag) {
        cout <<
            "Sorry, je bent te jong om mee te doen." << endl;
        return 1;
    }

    // Antwoord als de pesoon een niet bestaande dag invuld in deze maand
    // als hij/zij geboren is in dit jaar en deze maand. Niet dezelfde code
    // als hierboven, dit is door ongeldige datum i.p.v. te jong.
    if (Jaar - GeboorteJaar == 0 && 
        GeboorteMaand == Maand && GeboorteDag > Dag) {
        cout <<
            "Deze datum is ongeldig." << endl;
        return 1;
    }

    // De berekening van hoe oud de persoon is in jaren en maanden.
    if (GeboorteMaand < Maand) { 
        JaarOud = Jaar - GeboorteJaar; // Leeftijd in jaren
        if (GeboorteDag <= Dag) { 
            MaandOud = Maand - GeboorteMaand;
        } else {
            MaandOud = Maand - GeboorteMaand - 1; // Leeftijd in maanden
        }
    } // Het stuk code hierboven is bedoeld voor als iemand al jarig is 
      // geweest in een andere maand dan die van nu dit jaar. 
    if (GeboorteMaand == Maand) {
        if (GeboorteDag <= Dag) {
            JaarOud = Jaar - GeboorteJaar; // Leeftijd in jaren
            MaandOud = 0; // Leeftijd in maanden
        } else {
            JaarOud = Jaar - GeboorteJaar - 1; // Leeftijd in jaren
            MaandOud = 11; // Leeftijd in maanden
        }
    } // Het stuk code hierboven is bedoeld voor als iemand jarig is 
      // in de maand waar we nu inzitten. 
    if (GeboorteMaand > Maand) {
        JaarOud = Jaar - GeboorteJaar - 1; // Leeftijd in jaren
        if (GeboorteDag <= Dag) {
            MaandOud = Maand - GeboorteMaand + 12; // Leeftijd in maanden
        } else {
            MaandOud = Maand - GeboorteMaand + 11; // Leeftijd in maanden
        }
    } // Het stuk code hierboven is bedoeld voor als iemand nog jarig moet
      // worden in de aankomende maanden dit jaar. 
    MaandOudTot = JaarOud * 12 + MaandOud; // Totaal aantal maanden dat iemand
                                           // heeft geleeft.
    cout << "De exacte leeftijd is " << JaarOud << " jaar en " << MaandOud <<
        " maand(en) oud (" << MaandOudTot << " maanden in totaal)." << endl;

    // Bericht als iemand jarig is.
    if (MaandOud == 0 && GeboorteDag == Dag) {
        cout <<
            "Van harte gefeliciteerd, weer een jaarte ouder!" << endl;
    }

    // Bericht als ieamand maandig is.
    if (MaandOud != 0 && GeboorteDag == Dag) {
        cout <<
            "Van harte gefeliciteerd, weer een maandje ouder!" << endl;
    }

    // Hiermee wordt uitgerekend voor welke weekdag de datum is (eerst jaren).
    DagenTeller = 2 + 1461 * ((GeboorteJaar - 1901) / 4) + 
    365 * ((GeboorteJaar - 1) % 4);

    // Dagen voor maand erbij.
    if (GeboorteMaand == 1) {
        MaandTeller = 0;
    }
    if (GeboorteMaand == 2) {
        MaandTeller = 31;
    }
    if (GeboorteMaand == 3) {
        MaandTeller = 60;
    }
    if (GeboorteMaand == 4) {
        MaandTeller = 91;
    }
    if (GeboorteMaand == 5) {
        MaandTeller = 121;
    }
    if (GeboorteMaand == 6) {
        MaandTeller = 152;
    }
    if (GeboorteMaand == 7) {
        MaandTeller = 182;
    }
    if (GeboorteMaand == 8) {
        MaandTeller = 213;
    }
    if (GeboorteMaand == 9) {
        MaandTeller = 244;
    }
    if (GeboorteMaand == 10) {
        MaandTeller = 274;
    }
    if (GeboorteMaand == 11) {
        MaandTeller = 305;
    }
    if (GeboorteMaand == 12) {
        MaandTeller = 335;
    }

    // Als niet een schrikkeljaar -1 dag vanaf maart.
    if ((GeboorteJaar - 1901) % 4 != 3 && GeboorteMaand > 2) {
        MaandTeller -= 1;
    }
    DagenTeller += MaandTeller + GeboorteDag - 1;

    // Hiermee doen we het omreekenen naar dagen in de week.
    if (DagenTeller % 7 == 1) {
        WeekDagEnkel = 'm'; // eerst gedeeld door 7, en 1 staat dus
                            // voor de dag maandag. De rest van de dagen
                            // hebben andere cijfers.
    }
    if (DagenTeller % 7 == 2 || DagenTeller % 7 == 4) {
        WeekDagEnkel = 'd';
    }
    if (DagenTeller % 7 == 3) {
        WeekDagEnkel = 'w';
    }
    if (DagenTeller % 7 == 5) {
        WeekDagEnkel = 'v';
    }
    if (DagenTeller % 7 == 6 || DagenTeller % 7 == 0) {
        WeekDagEnkel = 'z';
    }
    if (DagenTeller % 7 == 2) {
        WeekDagDubbel = 'i';
    }
    if (DagenTeller % 7 == 4 || DagenTeller % 7 == 0) {
        WeekDagDubbel = 'o';
    }
    if (DagenTeller % 7 == 6) {
        WeekDagDubbel = 'a';
    }

    // Raden op welke dag de persoon geboren is.
    cout << "Op welke dag bent u geboren (m/d/w/d/v/z/z)? ";
    cin >> DagRaad1;
    if (DagRaad1 != WeekDagEnkel) {
        cout << "Dat is niet de correcte dag." << endl;
        return 1; // Antwoord als iemand de verkeerde dag invoert.
    }
    if (DagRaad1 == 'd' || DagRaad1 == 'z') {
        cout << "Wat is de tweede letter van de dag? ";
        cin >> DagRaad2;
        if (DagRaad2 != WeekDagDubbel) {
            cout << "Dat is niet de correcte dag." << endl;
            return 1; // Antwoord als iemand de verkeerde dag invoert.
        }
    }

    // Twee willekeurige getallen genereren.
    srand(MaandOudTot);
    Getal1 = rand() % 90 + 10;
    Getal2 = rand() % 90 + 10;

    // Mensen vanaf 30 jaar netter aanspreken.
    if (JaarOud > 29) {
        Aanspreek = "u heeft";
        Aanspreek2 = "U";
    } else {
        Aanspreek = "je hebt";
        Aanspreek2 = "Je";
    }

    // Rekenopdracht vraag.
    cout << "Schat het product van de volgende twee getallen: " <<
        endl;
    cout << Getal1 << " en " << Getal2 << endl;
    cin >> Gok;
    if (Gok < (1 - Epsilon) * Getal1 * Getal2 || 
        Gok > (1 + Epsilon) * Getal1 * Getal2) {
        cout << "Sorry, " << Aanspreek <<
            " het fout, de test is bij deze beëindigd. Het goede " <<
            "antwoord was: " << endl;
    } else {
        cout << "Gefeliciteerd, " << Aanspreek << " goed genoeg gegokt." <<
            " Zie hier het correcte antwoord: " << endl;
    } // Je mag maar epsilon naast het getal zitten. Per getal verschilt het.

    // Rekenopdracht antwoord.
    Getal2Mod10 = Getal2 % 10;
    if (Getal1 * Getal2 < 1000) { // Als getal onder 1000 is.
        cout << " " << Getal1 << endl;
        cout << " " << Getal2 << " x" << endl; // Zodat getallen mooi staan.
        cout << " --" << endl; // Streepjes onder de getallen.
        if (Getal2Mod10 != 0) {
            if (Getal2Mod10 * Getal1 < 100) {
                cout << " " << Getal2Mod10 * Getal1 << endl;
            } else {
                cout << Getal2Mod10 * Getal1 << endl;
            }
            cout << Getal1 * Getal2 - Getal1 * Getal2Mod10 << " +" << endl;
            cout << "---" << endl; // Streepjes onder de getallen.
            cout << Getal1 * Getal2 << endl; // Vermenigvuldiging.
        } else {
            cout << Getal1 * Getal2 - Getal1 * Getal2Mod10 << endl;
        }
    }
    if (Getal1 * Getal2 > 999) { // Als het getal boven 999 is. 
        cout << "  " << Getal1 << endl;
        cout << "  " << Getal2 << " x" << endl;
        cout << "  --" << endl;
        if (Getal2Mod10 != 0) {
            if (Getal2Mod10 * Getal1 < 100) {
                cout << "  " << Getal2Mod10 * Getal1 << endl;
            } else {
                cout << " " << Getal2Mod10 * Getal1 << endl;
            }
            cout << Getal1 * Getal2 - Getal1 * Getal2Mod10 << " +" << endl;
            if (Getal1 * Getal2 - Getal1 * Getal2Mod10 < 1000) {
                cout << "---" << endl;
            } else {
                cout << "----" << endl;
            }
            cout << Getal1 * Getal2 << endl;
        } else {
            cout << Getal1 * Getal2 - Getal1 * Getal2Mod10 << endl;
        }
    }

    // Controleer of iemand door mag naar studie of tweede vraag krijgt.
    if (Gok >= (1 - Epsilon) * Getal1 * Getal2 && 
        Gok <= (1 + Epsilon) * Getal1 * Getal2) {
        cout << Aanspreek2 << " bent toegelaten tot de studie." << endl;
        return 1;
    }
    cout << "Dat is incorrect. " << Aanspreek2 <<
        " moet nu de volgende vraag goed beantwoorden: " << endl;

    // Multiple-choice vraag vraag. 
    // Mensen krijgen een andere vraag als ze een boven 29 zijn, of onder 30.
    if (JaarOud > 29) {
        GoedAntwoord = "C: Verona";
        cout << "waar woonden Romeo en Julia? (Aa/Bb/Cc/Dd)" << endl;
        cout << "A: Venetië" << endl;
        cout << "B: Parijs" << endl;
        cout << "C: Verona" << endl;
        cout << "D: Lucca" << endl;
    } else {
        GoedAntwoord = "C: Beethoven";
        cout << "wie heeft Für Elise gecomponeerd? (Aa/Bb/Cc/Dd)" << endl;
        cout << "A: Mozart" << endl;
        cout << "B: Bach" << endl;
        cout << "C: Beethoven" << endl;
        cout << "D: Schubert" << endl;
    }
    
    // Multiple-choice vraag antwoord.
    cin >> Antwoord;
    if (Antwoord == 'C' || Antwoord == 'c') {
        cout << "Het antwoord was inderdaad " 
             << GoedAntwoord << ". " << Aanspreek2 
             << " bent toegelaten tot een universitaire alpha-studie." << endl;
    } else {
        cout << "Dat is incorrect. Het antwoord moest zijn: "  << GoedAntwoord
             << ". " << Aanspreek2  << " bent niet toegelaten tot een " 
             << "universitaire alpha-studie." << endl;
    }

} // main