#pragma once

#include "Properties.hpp"
#include "Common.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;

class WorldEditorObject
{
	private:
		Properties properties;

	public:
		WorldEditorObject();

		// Methods
		bool load(const string&);
		bool save(const string&);

		Properties& getProperties();

};
