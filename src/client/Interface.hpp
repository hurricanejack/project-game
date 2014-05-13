#pragma once

#include <SFGUI\SFGUI.hpp>
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Interface
{
	public:
		Interface();
		~Interface();
		virtual void setup(sfg::Desktop&);
		virtual string getName();
};