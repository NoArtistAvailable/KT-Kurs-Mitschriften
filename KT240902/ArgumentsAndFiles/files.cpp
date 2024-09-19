#include <iostream>
#include <fstream>	// file stream

int main() {
	std::fstream fileStream;			// Allgemeine Klasse für das Nutzen von Dateien
	std::ofstream outputFileStream;		// Klasse explizit zum beschreiben von Dateien
	std::ifstream inputFileStream;		// Klasse explizit für das Lesen von Dateien

	fileStream.open("data.txt", std::ios::out | std::ios::in);
	// ios::out		= Zum Schreiben oder Überschreiben	(Wenn die Datei nicht existiert, dann wird
	// ios::in		= Zum Lesen der Datei
	// ios::trunc	= Truncate		Datei wird beim Öffnen geleert
	// ios::app		= Append		Geschriebene Daten werden angehängt				(Dateizeiger wird immer ans Ende gesetzt)
	// ios::ate		= At The End	Positionszeiger wird ans Ende der Datei gesetzt	(Dateizeiger kann manuell verschoben werden)
	// ios::beg		= Begin			Positionszeiger wird an den Anfang der Datei gesetzt
	// ios::cur		= Current		Positionszeiger wird an die aktuelle Position im Dateistrom gesetzt
	// ios::binary	= Kann binäre Dateien öffnen und bearbeiten
	

	fileStream << "\nDieser Text geht in die Datei." << std::endl;
	fileStream.close();
}