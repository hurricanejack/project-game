#pragma once

#include <SFGUI\SFGUI.hpp>
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Interface
{
	protected:
		void* userData;
	public:
		Interface();
		virtual ~Interface();
		virtual void setup(sfg::Desktop&);
		virtual void remove(sfg::Desktop&);
		virtual string getName();
		void setUser(void*);
};