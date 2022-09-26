#include "Agent.h"
#include "Cat.h"
#include "Catcher.h"
#include "World.h"

int main() 
{
	World* world;
	Cat* cat;
	Catcher* catcher;

	cat->Move(world);
    catcher->Move(world);

	return 0;
}