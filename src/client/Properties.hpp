#pragma once

#include "Common.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;

class Properties
{
private:
	vector<Property> properties;
public:
	Properties();
	bool load(const string&);
	bool save(const string&);

	// Property control
	bool clearProperties();
	bool checkProperty(const string&);
	bool addProperty(const string&, const string&);
	bool setProperty(const string&, const string&);
	bool removeProperty(const string&);
	Property getProperty(const string&);
	vector<Property>& getProperties();
};