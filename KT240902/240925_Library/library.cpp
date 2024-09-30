//#include "library.h"
//#include "media.h"
#include <fstream>
using std::string;

//void Library::Init() {
//	ownedMedia = std::vector<Media>();
//	AddBooksFromDirectory("books.txt");
//}
//
//void Library::AddBooksFromDirectory(const string& path) {
//	auto newMedia = LoadMediaFromPath(path);
//	ownedMedia.insert(ownedMedia.end(), newMedia.begin(), newMedia.end());
//}

//std::vector<Media> Library::LoadMediaFromPath(const string& path) {
//	auto vec = std::vector<Media>();
//	std::ifstream fileStream;
//	fileStream.open(path, std::ios::in);
//	char buffer[256];
//	while (!fileStream.eof()) {
//		fileStream.getline(buffer, sizeof(buffer));
//		// query for title until we hit first ;
//		// query for author until we hit second ;
//		// query for tags until we hit third ;
//	}
//	fileStream.close();
//}