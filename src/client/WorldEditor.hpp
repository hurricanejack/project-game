#pragma once

#include "WorldEditorObject.hpp"

class WorldEditor
{
	private:
		vector<WorldEditorObject> objects;

		bool newWorld();
		bool saveWorld(const string&);
		bool loadWorld(const string&);

	public:
		WorldEditor();

		bool newProject();
		bool loadProject();
		bool saveProject();
		bool publishProject();

		vector<WorldEditorObject>& getObjects();

		void addObject(const WorldEditorObject&);

};

