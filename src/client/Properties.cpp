#include "Properties.hpp"
#include "pugixml.hpp"
using namespace pugi;

Properties::Properties()
{

}

bool Properties::load(const string& filename)
{

	properties.clear();

	xml_document doc;
	xml_parse_result result = doc.load_file(filename.c_str());

	if (!result)
	{
		return false;
	}

	//auto properties = doc.attribute("properties");
	auto properties = doc.child("properties");

	for (xml_node property : properties.children("property"))
	{
		Property p;

		p.Name = property.attribute("name").as_string();
		p.Type = property.attribute("type").as_string();
		p.Value = property.first_child().value();

		if (p.Name != "" && p.Value != "")
		{
			this->properties.push_back(p);
		}

	}

	return true;
}

bool Properties::save(const string& filename)
{
	return true;
}

bool Properties::clearProperties()
{
	properties.clear();
	return true;
}

Property Properties::getProperty(const string& name)
{
	Property p;
	for (unsigned int i = 0; i < properties.size(); i++)
	{
		if (properties.at(i).Name == name)
		{
			return properties.at(i);
		}
	}
	return p;
}

bool Properties::checkProperty(const string& name)
{
	Property p = getProperty(name);
	if (p.Name == "")
	{
		return false;
	}
	return true;
}

bool Properties::addProperty(const string& name, const string& value)
{
	if (checkProperty(name)){ return false; }
	Property p;
	p.Name = name;
	p.Value = value;
	properties.push_back(p);
	return true;
}

bool Properties::removeProperty(const string& name)
{
	for (unsigned int i = 0; i < properties.size(); i++)
	{
		if (properties.at(i).Name == name)
		{
			properties.erase(properties.begin() + i);
			return true;
		}
	}
	return false;
}

bool Properties::setProperty(const string& name, const string& value)
{
	if (!checkProperty(name)){ return false; }
	if (!removeProperty(name)){ return false; }
	if (!addProperty(name, value)){ return false; }
	return true;
}

vector<Property>& Properties::getProperties()
{
	return properties;
}
