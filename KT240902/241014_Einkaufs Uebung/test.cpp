#include "pch.h"
#include "einkaufsliste.h"
#include <string>
#include <regex>


TEST(EinkaufslistenTest, Hinzufuegen) {
	Einkaufsliste<Produkt> liste;
	liste.hinzufuegen(new LebensMittel("Packung Kaffee", 11, 800, 720 * 24 * 60 * 60));
	testing::internal::CaptureStdout();
	liste.anzeigen();
	std::string output = testing::internal::GetCapturedStdout();



	EXPECT_TRUE(std::regex_search(output, std::regex ("Kaffee")));
}

TEST(EinkaufslistenTest, Entfernen) {
	Einkaufsliste<Produkt> liste;

	auto kaffee = LebensMittel("Packung Kaffee", 11, 800, 720 * 24 * 60 * 60);

	liste.hinzufuegen(&kaffee, 20);
	liste.hinzufuegen(new LebensMittel("Packung Milch", 1.25, 500, 26 * 24 * 60 * 60));

	liste.entfernen(&kaffee);

	testing::internal::CaptureStdout();
	liste.anzeigen();
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_FALSE(std::regex_search(output, std::regex("Kaffee")));
}