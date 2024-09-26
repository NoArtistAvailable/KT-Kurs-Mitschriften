#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

/*Projekt Bibliothek
Projektbeschreibung:
Es soll eine Bibliothek simuliert werden mit einem Terminal/ Schalter, an
dem Aufgaben erledigt werden k�nnen wie z.B.
1. Medium/ Medien hinzuf�gen/ entfernen/ einsortieren
2. Suche nach Medien
3. Verleihstatus feststellen
4. Nutzer hinzuf�gen/ entfernen
Klassen sollen in *hpp und *cpp - Dateien modularisiert werden.
F�r Strukturen ohne Methoden gen�gen *hpp - Dateien.
Vorstellbar ist hier die Bibliothek als Singleton (kann sp�ter als solche
implementiert werden) und ggf. Aggregation mit den Klassen (bzw.
Strukturen) Nutzer, Medien, Regale.
Das Terminal ist der Entry- Point des Programms, solange es keine GUI
gibt.
Medien sollten als Klasse dargestellt werden, um damit eine Vererbung
vorzunehmen. Somit kann �Medien� als abstrakte Klasse implementiert
werden, von der sich dann z.B. �Buch�, , �CD� usw. ableiten
Medien- Attribute z.B.:
� Art (z.B. Buch, CD)
� Autor
� Titel (bei CDs zus�tzlich noch Titelliste)
� Kategorie (z.B. Sachbuch, Punkrock)
� Code (z.B. ISBN oder EAN)
� letzter Nutzer
� Timestamp, wenn verliehen
Das Hinzuf�gen soll �ber eine CSV- Datei erfolgen und in einen
geeigneten C++ Container eingelesen werden. Aus diesem soll gesucht und
entfernt werden. Zu einem sp�teren Zeitpunkt soll eine Datenbank
einbezogen werden.
�berziehungen sollen anhand des Timestamps ermittelt werden (Alarm/
Reporting?).
Die Nutzer sollen neben den typischen Attributen
� Name
� Adresse
� Kontakt
auch eine Mitgliedsnummer bekommen, die aus den Initialen am Beginn
besteht gefolgt von 5- stelligen Ziffernfolge, deren letzte eine Pr�fziffer ist,
die als Modulo 10 der Summe aller Ziffern berechnet wird.
Regale (als Vectoren/ Map ?) sollen mit Medien jeder Art bef�llt werden
k�nnen. Das Einsortieren soll �ber eine Funktion erfolgen, die manuell
ausgef�hrt werden kann (um Neuzug�nge einsortieren zu k�nnen), aber bei
Programmstart auch automatisch einmal aufgerufen wird. Regale sollen
eine bestimmte Gr��e (Kapazit�t) nicht �berschreiten k�nnen.*/