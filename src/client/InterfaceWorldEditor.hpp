#pragma once

#include "WorldEditor.hpp"
#include "Interface.hpp"
#include <SFGUI\SFGUI.hpp>
#include "Scene.hpp"
#include "SceneEditor.hpp"
#include <vector>
#include <string>
using std::vector;
using std::string;

struct Tool
{
	bool Loaded{ false };
	string Name{ "Tool" };
	string Filename{ "" };
	sfg::Image::Ptr Image;
	sf::Image img;
	Tool(){};
	Tool(const string& n, const string& f)
	{
		Name = n;
		Filename = f;
	}
	bool load()
	{
		if (!img.loadFromFile(Filename))
		{
			return false;
		}
		Image = sfg::Image::Create(img);
		Loaded = true;
		return true;
	}
};

class InterfaceWorldEditor : public Interface
{
	private:

		// Windows
		sfg::Window::Ptr windowProperties;		// Property window
		sfg::Window::Ptr windowObjectBrowser;	// Object browser window
		sfg::Window::Ptr windowLayer;			// Layer window
		sfg::Window::Ptr windowTool;			// Tool window

		// Storage for tools
		vector<Tool> tools;

			// For tools window
			sfg::Box::Ptr toolsBox;
			vector<sfg::ToggleButton::Ptr> toolButtons;

		// Storage for properties
		vector<Property> properties;

			// For properties window
			sfg::Box::Ptr propertiesBox;
			vector<sfg::Label::Ptr> windowPropertiesLabel;
			vector<sfg::Entry::Ptr> windowPropertiesTextbox;
			vector<sfg::Box::Ptr> windowPropertiesBox;

			// For layers window
			sfg::Box::Ptr boxLayer;
			sfg::ToggleButton::Ptr buttonLayerBackground;
			sfg::ToggleButton::Ptr buttonLayerTerrain;
			sfg::ToggleButton::Ptr buttonLayerObject;
			sfg::ToggleButton::Ptr buttonLayerForeground;
			sfg::ToggleButton::Ptr buttonLayerAudio;
			sfg::ToggleButton::Ptr buttonLayerAll;

		SceneEditor* scene;

		void loadImageFor(sfg::ToggleButton::Ptr& w, const string& fn)
		{
			sf::Image img;
			if (!img.loadFromFile(fn)){ return; }
			w->SetImage(sfg::Image::Create(img));
		}

	public:
		// Constructor
		InterfaceWorldEditor(Scene* s) :Interface()
		{

			tools.push_back({"Select","Resources\\gfx\\worldeditor\\tool_select.png"});
			tools.push_back({ "Rotate", "Resources\\gfx\\worldeditor\\tool_rotate.png" });
			tools.push_back({ "Scale", "Resources\\gfx\\worldeditor\\tool_scale.png" });
			tools.push_back({ "Camera", "Resources\\gfx\\worldeditor\\tool_camera.png" });

			// Import scene pointer
			scene = reinterpret_cast<SceneEditor*>(s);

			// Setup windows
			float propHeight = (scene->getGUIHeight() / 5) * 4;
			
			windowProperties	= sfg::Window::Create(sfg::Window::Style::TITLEBAR | sfg::Window::Style::BACKGROUND);
			windowProperties->SetTitle("Properties");
			windowProperties->SetPosition(sf::Vector2f(10.0f,10.0f));
			windowProperties->SetRequisition(sf::Vector2f(300.0f,propHeight));

			windowObjectBrowser = sfg::Window::Create(sfg::Window::Style::TITLEBAR | sfg::Window::Style::BACKGROUND);
			windowObjectBrowser->SetTitle("Object Browser");
			windowObjectBrowser->SetPosition(sf::Vector2f(10.0f, propHeight + 10.0f + 5.0f));
			windowObjectBrowser->SetRequisition(sf::Vector2f(scene->getGUIWidth() - 20.0f, scene->getGUIHeight() - propHeight - 20.0f - 10.0f));

			windowLayer = sfg::Window::Create(sfg::Window::Style::TITLEBAR | sfg::Window::Style::BACKGROUND);
			windowLayer->SetTitle("Layers");
			windowLayer->SetPosition(sf::Vector2f(350.0f,propHeight-90.0f));
			windowLayer->SetRequisition(sf::Vector2f(400.0f,50.0f));


				// Populate layer window
				boxLayer = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 5.0f);

				buttonLayerBackground = sfg::ToggleButton::Create();
				//buttonLayerBackground->SetLabel("Background");
				buttonLayerBackground->GetSignal(sfg::ToggleButton::OnLeftClick).Connect(std::bind(&InterfaceWorldEditor::onButtonLayerBackground, this));

				buttonLayerTerrain = sfg::ToggleButton::Create();
				//buttonLayerTerrain->SetLabel("Terrain");
				buttonLayerTerrain->GetSignal(sfg::ToggleButton::OnLeftClick).Connect(std::bind(&InterfaceWorldEditor::onButtonLayerTerrain, this));

				buttonLayerObject = sfg::ToggleButton::Create();
				//buttonLayerObject->SetLabel("Object");
				buttonLayerObject->GetSignal(sfg::ToggleButton::OnLeftClick).Connect(std::bind(&InterfaceWorldEditor::onButtonLayerObject, this));

				buttonLayerForeground = sfg::ToggleButton::Create();
				//buttonLayerForeground->SetLabel("Foreground");
				buttonLayerForeground->GetSignal(sfg::ToggleButton::OnLeftClick).Connect(std::bind(&InterfaceWorldEditor::onButtonLayerForeground, this));

				buttonLayerAudio = sfg::ToggleButton::Create();
				//buttonLayerAudio->SetLabel("Audio");
				buttonLayerAudio->GetSignal(sfg::ToggleButton::OnLeftClick).Connect(std::bind(&InterfaceWorldEditor::onButtonLayerAudio, this));

				buttonLayerAll = sfg::ToggleButton::Create();
				//buttonLayerAll->SetLabel("All");
				buttonLayerAll->SetActive(true);
				buttonLayerAll->GetSignal(sfg::ToggleButton::OnLeftClick).Connect(std::bind(&InterfaceWorldEditor::onButtonLayerAll,this));

				loadImageFor(buttonLayerBackground, "Resources\\gfx\\worldeditor\\layer_background.png");
				loadImageFor(buttonLayerTerrain, "Resources\\gfx\\worldeditor\\layer_terrain.png");
				loadImageFor(buttonLayerObject, "Resources\\gfx\\worldeditor\\layer_object.png");
				loadImageFor(buttonLayerForeground, "Resources\\gfx\\worldeditor\\layer_foreground.png");
				loadImageFor(buttonLayerAudio, "Resources\\gfx\\worldeditor\\layer_sound.png");
				loadImageFor(buttonLayerAll, "Resources\\gfx\\worldeditor\\layer_all.png");

				boxLayer->Pack(buttonLayerBackground);
				boxLayer->Pack(buttonLayerTerrain);
				boxLayer->Pack(buttonLayerObject);
				boxLayer->Pack(buttonLayerForeground);
				boxLayer->Pack(buttonLayerAudio);
				boxLayer->Pack(buttonLayerAll);

				windowLayer->Add(boxLayer);


			windowTool = sfg::Window::Create(sfg::Window::Style::TITLEBAR | sfg::Window::Style::BACKGROUND);
			windowTool->SetTitle("Tools");
			windowTool->SetPosition(sf::Vector2f(scene->getGUIWidth()-100.0f,10.0f));
			windowTool->SetRequisition(sf::Vector2f(80.0f,propHeight));

			refreshPropertiesWindow();
			refreshToolsWindow();

		}

		void clearToolsWindow()
		{
			windowTool->RemoveAll();
			toolButtons.clear();
		}

		void refreshToolsWindow()
		{
			clearToolsWindow();

			toolsBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);

			for (unsigned int i = 0; i < tools.size(); i++)
			{
				Tool tool = tools.at(i);
				bool loaded = false;
				if (!tool.Loaded)
				{
					if (tool.load())
					{
						loaded = true;
					}
				}
				else
				{
					loaded = true;
				}
				sfg::ToggleButton::Ptr button = sfg::ToggleButton::Create();
				
				button->SetLabel("");

				if (loaded)
				{
					button->SetImage(tool.Image);
				}
				else
				{
					button->SetLabel(tool.Name);
				}

				button->GetSignal(sfg::ToggleButton::OnLeftClick).Connect(std::bind(&InterfaceWorldEditor::onButtonTool, this));
				if (i == 0)
				{
					button->SetActive(true);
				}
				toolButtons.push_back(button);
				toolsBox->Pack(button,false,false);
			}
			windowTool->Add(toolsBox);

		}

		void onButtonTool()
		{
			// Figure out which button was pressed
			int pressed = -1;

			for (unsigned int i = 0; i < toolButtons.size(); i++)
			{
				auto child = toolButtons.at(i);
				cout << (int)child->GetState() << endl;
				child->GetId();
				if (child->GetState() == sfg::ToggleButton::State::INSENSITIVE)
				{
					pressed = i;
					break;
				}
			}

			if (pressed == -1){ return;  }

			cout << "Pressed " << pressed << endl;

			auto child = toolButtons.at(pressed);
			if (!child->IsActive())
			{
				child->SetActive(true);
			}

			for (unsigned int i = 0; i < toolButtons.size(); i++)
			{
				if (i != pressed)
				{
					auto child = toolButtons.at(i);
					child->SetActive(false);
				}
			}

		}

		void clearProperties()
		{
			properties.clear();
			windowProperties->SetTitle("World Properties");
		}

		void setProperties(const vector<Property>& list)
		{
			properties = list;

			// Find a name
			for (unsigned int i = 0; i < properties.size(); i++)
			{
				if (properties.at(i).Name == "name")
				{
					windowProperties->SetTitle("Properties for '" + properties.at(i).Value + "'");
					break;
				}
			}

			refreshPropertiesWindow();

		}

		void clearPropertiesWindow()
		{
			windowProperties->RemoveAll();
			windowPropertiesLabel.clear();
			windowPropertiesTextbox.clear();
			windowPropertiesBox.clear();
		}

		void refreshPropertiesWindow()
		{
			clearPropertiesWindow();

			propertiesBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 2.0f);
			windowProperties->Add(propertiesBox);
			//windowProperties->SetRequisition(sf::Vector2f(150.0f,400.0f));

			for (unsigned int i = 0; i < properties.size(); i++)
			{

				sfg::Label::Ptr label	= sfg::Label::Create();
				sfg::Entry::Ptr textbox = sfg::Entry::Create();
				sfg::Box::Ptr	box		= sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 5.0f);

				box->SetRequisition(sf::Vector2f(300.0f, 28.0f));
				textbox->SetRequisition(sf::Vector2f(200.0f,25.0f));
				label->SetRequisition(sf::Vector2f(100.0f, 25.0f));

				label->SetText(properties.at(i).Name);
				textbox->SetText(properties.at(i).Value);

				windowPropertiesBox.push_back(box);
				windowPropertiesLabel.push_back(label);
				windowPropertiesTextbox.push_back(textbox);

				box->Pack(label,false,false);
				box->Pack(textbox,false,false);

				propertiesBox->Pack(box,false,false);

			}

		}

		void setup(sfg::Desktop& desktop)
		{
			desktop.Add(windowProperties);
			desktop.Add(windowObjectBrowser);
			desktop.Add(windowLayer);
			desktop.Add(windowTool);
		}

		void remove(sfg::Desktop& desktop)
		{
			desktop.Remove(windowProperties);
			desktop.Remove(windowObjectBrowser);
			desktop.Remove(windowLayer);
			desktop.Remove(windowTool);
		}

		string getName()
		{
			return "InterfaceWorldEditor";
		}

		// Destrustor
		~InterfaceWorldEditor()
		{

		}

		void onButtonLayerAll()
		{
			buttonLayerForeground->SetActive(false);
			buttonLayerObject->SetActive(false);
			buttonLayerAudio->SetActive(false);
			buttonLayerBackground->SetActive(false);
			buttonLayerTerrain->SetActive(false);
			if (!buttonLayerAll->IsActive())
			{
				buttonLayerAll->SetActive(true);
			}
		}

		void onButtonLayerAudio()
		{
			buttonLayerAll->SetActive(false);
			buttonLayerForeground->SetActive(false);
			buttonLayerObject->SetActive(false);
			buttonLayerBackground->SetActive(false);
			buttonLayerTerrain->SetActive(false);
			if (!buttonLayerAudio->IsActive())
			{
				buttonLayerAudio->SetActive(true);
			}
		}

		void onButtonLayerTerrain()
		{
			buttonLayerAll->SetActive(false);
			buttonLayerForeground->SetActive(false);
			buttonLayerObject->SetActive(false);
			buttonLayerAudio->SetActive(false);
			buttonLayerBackground->SetActive(false);
			if (!buttonLayerTerrain->IsActive())
			{
				buttonLayerTerrain->SetActive(true);
			}
		}

		void onButtonLayerObject()
		{


			buttonLayerAll->SetActive(false);
			buttonLayerForeground->SetActive(false);
			buttonLayerAudio->SetActive(false);
			buttonLayerBackground->SetActive(false);
			buttonLayerTerrain->SetActive(false);
			if (!buttonLayerObject->IsActive())
			{
				buttonLayerObject->SetActive(true);
			}
		}

		void onButtonLayerBackground()
		{
			buttonLayerAll->SetActive(false);
			buttonLayerForeground->SetActive(false);
			buttonLayerObject->SetActive(false);
			buttonLayerAudio->SetActive(false);
			buttonLayerTerrain->SetActive(false);
			if (!buttonLayerBackground->IsActive())
			{
				buttonLayerBackground->SetActive(true);
			}
		}

		void onButtonLayerForeground()
		{
			buttonLayerAll->SetActive(false);
			buttonLayerObject->SetActive(false);
			buttonLayerAudio->SetActive(false);
			buttonLayerBackground->SetActive(false);
			buttonLayerTerrain->SetActive(false);
			if (!buttonLayerForeground->IsActive())
			{
				buttonLayerForeground->SetActive(true);
			}
		}






};