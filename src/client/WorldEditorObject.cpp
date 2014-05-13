#include "WorldEditorObject.hpp"


WorldEditorObject::WorldEditorObject()
{

}

bool WorldEditorObject::load(const string& foldername)
{
	string propertyFile = foldername + "\\properties.xml";
	if (!properties.load(propertyFile)){ return false; }
	return true;
}

bool WorldEditorObject::save(const string& foldername)
{
	string propertyFile = foldername + "\\properties.xml";
	if (!properties.save(propertyFile)){ return false; }
	return true;
}

Properties& WorldEditorObject::getProperties()
{
	return properties;
}