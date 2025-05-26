#include "Pig.h"
class SandBox : public Pig::Application {
public:
	SandBox() {

	}
	~SandBox()
	{

	}

};
Pig::Application* Pig::CreateApplication() {
	return new SandBox();
}