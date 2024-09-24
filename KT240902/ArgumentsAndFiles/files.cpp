#include <iostream>
#include <fstream>	// file stream


int main(int argc, char** argv) {
	std::fstream fileStream;			// Allgemeine Klasse für das Nutzen von Dateien
	std::ofstream outputFileStream;		// Klasse explizit zum beschreiben von Dateien
	std::ifstream inputFileStream;		// Klasse explizit für das Lesen von Dateien

	fileStream.open("data.txt", std::ios::app);
	// directory muss existieren, ansonsten wird die datei nicht erstellt
	// 
	// ios::out		= Zum Schreiben oder Überschreiben	(Wenn die Datei nicht existiert, dann wird
	// ios::in		= Zum Lesen der Datei
	// ios::trunc	= Truncate		Datei wird beim Öffnen geleert
	// ios::app		= Append		Geschriebene Daten werden angehängt				(Dateizeiger wird immer ans Ende gesetzt)
	// ios::ate		= At The End	Positionszeiger wird ans Ende der Datei gesetzt	(Dateizeiger kann manuell verschoben werden)
	// ios::beg		= Begin			Positionszeiger wird an den Anfang der Datei gesetzt
	// ios::cur		= Current		Positionszeiger wird an die aktuelle Position im Dateistrom gesetzt
	// ios::binary	= Kann binäre Dateien öffnen und bearbeiten


	const char* someData = "\nMy Favorite data\nIs Here";
	fileStream.write(someData, strlen(someData));
	fileStream.close();

	//if(fileStream.good()) {}	// check what this does (?)

	fileStream.open("data.txt", std::ios::in);
	char buffer[256];
	while (!fileStream.eof()) {
		fileStream.getline(buffer, sizeof(buffer));
		std::cout << sizeof(buffer) << " " << buffer << std::endl;
	}

	fileStream << "\nDieser Text geht in die Datei." << std::endl;
	fileStream.close();
}