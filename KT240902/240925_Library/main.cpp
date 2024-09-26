#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

/*Projekt Bibliothek
Projektbeschreibung:
Es soll eine Bibliothek simuliert werden mit einem Terminal/ Schalter, an
dem Aufgaben erledigt werden können wie z.B.
1. Medium/ Medien hinzufügen/ entfernen/ einsortieren
2. Suche nach Medien
3. Verleihstatus feststellen
4. Nutzer hinzufügen/ entfernen
Klassen sollen in *hpp und *cpp - Dateien modularisiert werden.
Für Strukturen ohne Methoden genügen *hpp - Dateien.
Vorstellbar ist hier die Bibliothek als Singleton (kann später als solche
implementiert werden) und ggf. Aggregation mit den Klassen (bzw.
Strukturen) Nutzer, Medien, Regale.
Das Terminal ist der Entry- Point des Programms, solange es keine GUI
gibt.
Medien sollten als Klasse dargestellt werden, um damit eine Vererbung
vorzunehmen. Somit kann ‚Medien‘ als abstrakte Klasse implementiert
werden, von der sich dann z.B. ‚Buch‘, , ‚CD‘ usw. ableiten
Medien- Attribute z.B.:
• Art (z.B. Buch, CD)
• Autor
• Titel (bei CDs zusätzlich noch Titelliste)
• Kategorie (z.B. Sachbuch, Punkrock)
• Code (z.B. ISBN oder EAN)
• letzter Nutzer
• Timestamp, wenn verliehen
Das Hinzufügen soll über eine CSV- Datei erfolgen und in einen
geeigneten C++ Container eingelesen werden. Aus diesem soll gesucht und
entfernt werden. Zu einem späteren Zeitpunkt soll eine Datenbank
einbezogen werden.
Überziehungen sollen anhand des Timestamps ermittelt werden (Alarm/
Reporting?).
Die Nutzer sollen neben den typischen Attributen
• Name
• Adresse
• Kontakt
auch eine Mitgliedsnummer bekommen, die aus den Initialen am Beginn
besteht gefolgt von 5- stelligen Ziffernfolge, deren letzte eine Prüfziffer ist,
die als Modulo 10 der Summe aller Ziffern berechnet wird.
Regale (als Vectoren/ Map ?) sollen mit Medien jeder Art befüllt werden
können. Das Einsortieren soll über eine Funktion erfolgen, die manuell
ausgeführt werden kann (um Neuzugänge einsortieren zu können), aber bei
Programmstart auch automatisch einmal aufgerufen wird. Regale sollen
eine bestimmte Größe (Kapazität) nicht überschreiten können.*/