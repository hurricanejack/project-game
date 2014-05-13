#pragma once

#include "Interface.hpp"
#include <SFGUI\SFGUI.hpp>

class InterfaceWorldEditorFirst : public Interface
{
	private:
		sfg::Window::Ptr window;

		sfg::Button::Ptr button_newworld;
		sfg::Button::Ptr button_loadworld;
		sfg::Button::Ptr button_exit;

		sfg::Box::Ptr box;

	public:
		// Constructor
		InterfaceWorldEditorFirst() :Interface()
		{

			// Setup window
			window = sfg::Window::Create();
			window->SetTitle("World Editor 0.1");
			window->SetPosition(sf::Vector2f(200.0f, 200.0f));

			box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 40.0f);

			button_newworld = sfg::Button::Create("New World");
			button_loadworld = sfg::Button::Create("Load World");
			button_exit = sfg::Button::Create("Exit World Editor");

			button_newworld->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&InterfaceWorldEditorFirst::onButtonNew, this));
			button_loadworld->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&InterfaceWorldEditorFirst::onButtonLoad, this));
			button_exit->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&InterfaceWorldEditorFirst::onButtonExit, this));

			box->Pack(button_newworld);
			box->Pack(button_loadworld);
			box->Pack(button_exit);

			window->Add(box);
		}

		void setup(sfg::Desktop& desktop)
		{
			desktop.Add(window);
		}

		string getName()
		{
			return "InterfaceWorldEditorFirst";
		}

		void onButtonNew()
		{

		}

		void onButtonLoad()
		{

		}

		void onButtonExit()
		{
			//stopWorldEditor = true;
		}

		// Destrustor
		~InterfaceWorldEditorFirst()
		{
			
		}
};