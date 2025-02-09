#include "Application.h"
#include <iostream>
using namespace std;
namespace Hazel {

	Application::Application() {
	}

	Application::~Application() {
	}

	void Application::Run() {
		while (true) {
			cout<<"RunningInApplication"<<endl;
		}
	}
}