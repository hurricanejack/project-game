#include "WorldEditor.hpp"

WorldEditor::WorldEditor()
{

}

bool WorldEditor::newProject()
{
	return true;
}

bool WorldEditor::loadProject()
{
	return true;
}

bool WorldEditor::saveProject()
{
	return true;
}

bool WorldEditor::publishProject()
{
	return true;
}


bool WorldEditor::newWorld()
{
	objects.clear();
	return true;
}

bool WorldEditor::saveWorld(const string&)
{
	return true;
}

bool WorldEditor::loadWorld(const string&)
{
	return true;
}

vector<WorldEditorObject>& WorldEditor::getObjects()
{
	return objects;
}

void WorldEditor::addObject(const WorldEditorObject& o)
{
	objects.push_back(o);
}