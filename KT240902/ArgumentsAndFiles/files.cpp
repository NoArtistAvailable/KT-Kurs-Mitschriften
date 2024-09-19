#include <iostream>
#include <fstream>	// file stream

int main() {
	std::fstream fileStream;			// Allgemeine Klasse f�r das Nutzen von Dateien
	std::ofstream outputFileStream;		// Klasse explizit zum beschreiben von Dateien
	std::ifstream inputFileStream;		// Klasse explizit f�r das Lesen von Dateien

	fileStream.open("data.txt", std::ios::out | std::ios::in);
	// ios::out		= Zum Schreiben oder �berschreiben	(Wenn die Datei nicht existiert, dann wird
	// ios::in		= Zum Lesen der Datei
	// ios::trunc	= Truncate		Datei wird beim �ffnen geleert
	// ios::app		= Append		Geschriebene Daten werden angeh�ngt				(Dateizeiger wird immer ans Ende gesetzt)
	// ios::ate		= At The End	Positionszeiger wird ans Ende der Datei gesetzt	(Dateizeiger kann manuell verschoben werden)
	// ios::beg		= Begin			Positionszeiger wird an den Anfang der Datei gesetzt
	// ios::cur		= Current		Positionszeiger wird an die aktuelle Position im Dateistrom gesetzt
	// ios::binary	= Kann bin�re Dateien �ffnen und bearbeiten
	

	fileStream << "\nDieser Text geht in die Datei." << std::endl;
	fileStream.close();
}