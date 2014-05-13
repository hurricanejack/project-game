#pragma once

#include "WorldEditorObject.hpp"
#include "Properties.hpp"

class WorldEditor
{
	private:
		vector<WorldEditorObject> objects;

		bool newWorld();
		bool saveWorld(const string&);
		bool loadWorld(const string&);

		Properties properties;

	public:
		WorldEditor();

		bool newProject();
		bool loadProject();
		bool saveProject();
		bool publishProject();

		vector<WorldEditorObject>& getObjects();
		Properties& getProperties();

		void addObject(const WorldEditorObject&);

};

