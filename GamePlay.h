#pragma once
#include <SFML\Graphics.hpp>
#include "Personaje.h"
#include "Carpincho.h"
#include "CarpinchoCopado.h"

class GamePlay: public sf::Drawable
{
private:
	Personaje _player;
	Carpincho _carpincho;
public:
	GamePlay();
	//void aceleracion(Personaje repartidor, sf::Sprite aux);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

