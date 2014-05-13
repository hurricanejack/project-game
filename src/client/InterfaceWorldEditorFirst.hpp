#pragma once

#include "Interface.hpp"
#include <SFGUI\SFGUI.hpp>
#include "Scene.hpp"
#include "SceneEditor.hpp"

class InterfaceWorldEditorFirst : public Interface
{
	private:
		sfg::Window::Ptr window;

		sfg::Button::Ptr button_newworld;
		sfg::Button::Ptr button_loadworld;
		sfg::Button::Ptr button_publishworld;
		sfg::Button::Ptr button_exit;

		sfg::Box::Ptr box;

		SceneEditor* scene;

	public:
		// Constructor
		InterfaceWorldEditorFirst(Scene* s) :Interface()
		{

			scene = reinterpret_cast<SceneEditor*>(s);

			// Setup window
			window = sfg::Window::Create();
			window->SetTitle("World Editor 0.1");
			window->SetPosition(sf::Vector2f(200.0f, 200.0f));

			box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 40.0f);

			button_newworld = sfg::Button::Create("New World");
			button_loadworld = sfg::Button::Create("Load World");
			button_publishworld = sfg::Button::Create("Publish World");
			button_exit = sfg::Button::Create("Exit World Editor");

			button_newworld->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&SceneEditor::onButtonNewProject, scene));
			button_loadworld->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&SceneEditor::onButtonLoadProject, scene));
			button_publishworld->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&SceneEditor::onButtonPublishProject, scene));
			button_exit->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&SceneEditor::onButtonExitWorldEditor, scene));

			box->Pack(button_newworld);
			box->Pack(button_loadworld);
			box->Pack(button_publishworld);
			box->Pack(button_exit);

			window->Add(box);
		}

		void setup(sfg::Desktop& desktop)
		{
			desktop.Add(window);
		}

		void remove(sfg::Desktop& desktop)
		{
			desktop.Remove(window);
		}

		string getName()
		{
			return "InterfaceWorldEditorFirst";
		}

		// Destrustor
		~InterfaceWorldEditorFirst()
		{
			
		}
};