#pragma once

#include "Common.hpp"
#include "Interface.hpp"
#include <SFGUI\SFGUI.hpp>
#include "SceneTitle.hpp"

class InterfaceMenuMain : public Interface
{
private:
	sfg::Window::Ptr window;

	sfg::Button::Ptr button_singleplayer;
	sfg::Button::Ptr button_multiplayer;
	sfg::Button::Ptr button_worldeditor;
	sfg::Button::Ptr button_options;
	sfg::Button::Ptr button_exit;

	sfg::Box::Ptr box;

	SceneTitle* title;

public:
	// Constructor
	InterfaceMenuMain(Scene* s) :Interface()
	{

		title = reinterpret_cast<SceneTitle*>(s);

		// Setup window
		window = sfg::Window::Create();
		window->SetTitle("ProjectGame Alpha R1");
		window->SetPosition(sf::Vector2f(200.0f, 200.0f));

		box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 10.0f);

		// Setup buttons
		button_singleplayer = sfg::Button::Create("Singleplayer");
		button_multiplayer	= sfg::Button::Create("Multiplayer");
		button_worldeditor	= sfg::Button::Create("World Editor");
		button_options		= sfg::Button::Create("Options");
		button_exit			= sfg::Button::Create("Exit game");

		button_singleplayer->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&SceneTitle::onButtonSingleplayer, title));
		button_multiplayer->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&SceneTitle::onButtonMultiplayer, title));
		button_worldeditor->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&SceneTitle::onButtonWorldEditor, title));
		button_options->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&SceneTitle::onButtonOptions, title));
		button_exit->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&SceneTitle::onButtonExit, title));

		box->Pack(button_singleplayer);
		box->Pack(button_multiplayer);
		box->Pack(button_worldeditor);
		box->Pack(button_options);
		box->Pack(button_exit);

		window->Add(box);

		// Add elements to desktop
		

	}

	void setup(sfg::Desktop& desktop)
	{
		desktop.Add(window);
	}

	string getName()
	{
		return "InterfaceMenuMain";
	}

	void onButtonSingleplayer()
	{

	}

	void onButtonMultiplayer()
	{

	}

	void onButtonWorldEditor()
	{

	}

	void onButtonOptions()
	{

	}

	void onButtonExit()
	{
		gameRunning = false;
	}

	// Destrustor
	~InterfaceMenuMain()
	{

	}
};