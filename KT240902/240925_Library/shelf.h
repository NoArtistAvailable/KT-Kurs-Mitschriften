#pragma once
#include<vector>
#include "media.h"

class Shelf {
public:
	std::vector<Media*> content;
	int capacity;
};