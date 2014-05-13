#include "WorldEditorObject.hpp"


WorldEditorObject::WorldEditorObject()
{

}

bool WorldEditorObject::load(const string& filename)
{
	return true;
}

bool WorldEditorObject::save(const string& filename)
{
	return true;
}

bool WorldEditorObject::clearProperties()
{
	properties.clear();
	return true;
}

Property WorldEditorObject::getProperty(const string& name)
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

bool WorldEditorObject::checkProperty(const string& name)
{
	Property p = getProperty(name);
	if (p.Name == "")
	{
		return false;
	}
	return true;
}

bool WorldEditorObject::addProperty(const string& name, const string& value)
{
	if (checkProperty(name)){ return false; }
	Property p;
	p.Name = name;
	p.Value = value;
	properties.push_back(p);
	return true;
}

bool WorldEditorObject::removeProperty(const string& name)
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

bool WorldEditorObject::setProperty(const string& name, const string& value)
{
	if (!checkProperty(name)){ return false; }
	if (!removeProperty(name)){ return false; }
	if (!addProperty(name, value)){ return false; }
	return true;
}

bool WorldEditorObject::loadPropertiesFromString(const string&){ return true; }
bool WorldEditorObject::savePropertiesToString(string&){ return true; }

vector<Property>& WorldEditorObject::getProperties()
{
	return properties;
}
