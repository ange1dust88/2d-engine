#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engine.h"
#include "PrimitiveRenderer.h"



int main()
{
    Engine tyty = Engine(60, "b00m", 800, 600);
    tyty.run();
    return 0;
}