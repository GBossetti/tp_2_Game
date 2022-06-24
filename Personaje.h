#pragma once
#include <SFML\Graphics.hpp>
#include "Collisionable.h"

class Personaje: public sf::Drawable, public sf::Transformable , public Collisionable
{
private: 
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _velocity;
	bool _inmunidad;
	int _aceleracion;
public: 
	Personaje();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getBounds() const override;
	void setInmunidad(bool inmunidad);
	bool getInmunidad();
	void setAceleracion(int aceleracion);
	int getAceleracion();

};

