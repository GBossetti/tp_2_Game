#include "Personaje.h"

Personaje::Personaje()
{
    _velocity = { 0,0 };
    _inmunidad = false;
	_texture.loadFromFile("repartidor.png");
	_sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
    _sprite.setPosition(600 / 2 , 800 - _sprite.getGlobalBounds().height);
    _aceleracion = 6;
}

void Personaje::update()
{
    /*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _sprite.move(0, -_velocity);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _sprite.move(-_velocity, -0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _sprite.move(0, _velocity);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _sprite.move(_velocity, 0);
    }
    */

    /*
    if (_sprite.getPosition().x < 0) {
        _sprite.setPosition(0, _sprite.getPosition().y);
    }
    if (_sprite.getPosition().y < 0) {
        _sprite.setPosition(_sprite.getPosition().x, 0);
    }
    if (_sprite.getPosition().x + _sprite.getGlobalBounds().width > 800) {
        _sprite.setPosition(800 - _sprite.getGlobalBounds().width, _sprite.getPosition().y);
    }
    if (_sprite.getPosition().y + _sprite.getGlobalBounds().height > 600) {
        _sprite.setPosition(_sprite.getPosition().x, 600 - _sprite.getGlobalBounds().height);
    }
    */
   
    _velocity = { 0,0 };
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _velocity.y = -4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _velocity.x = -4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
       _velocity.y = 4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _velocity.x = 4;
    }

    _sprite.move(_velocity);
    
    
    if (_sprite.getGlobalBounds().left < 150) {
        _sprite.setPosition(150 + _sprite.getOrigin().x, _sprite.getPosition().y);
    }

    
    /*if (_sprite.getGlobalBounds().left < 0) {
        _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
    }*/

    //if (_sprite.getGlobalBounds().top < 300) {
    //    _sprite.setPosition(_sprite.getPosition().x, 300 + _sprite.getOrigin().y);
    //}
    
    if (_sprite.getGlobalBounds().top < 0) {
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y);
    }

    if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 450) {
        _sprite.setPosition(450 - (_sprite.getGlobalBounds().width - _sprite.getOrigin().x), _sprite.getPosition().y);
    }

    if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800) {
        _sprite.setPosition(800 - (_sprite.getGlobalBounds().width - _sprite.getOrigin().x), _sprite.getPosition().y);
    }

    if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 600) {
        _sprite.setPosition(_sprite.getPosition().x, 600 + (_sprite.getGlobalBounds().height - _sprite.getOrigin().y));
    }
}

void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

sf::FloatRect Personaje::getBounds() const
{
    return _sprite.getGlobalBounds();
}

void Personaje::setInmunidad(bool inmunidad)
{
    _inmunidad = inmunidad;
}

bool Personaje::getInmunidad()
{
    return _inmunidad;
}

void Personaje::setAceleracion(int aceleracion)
{
    _aceleracion = _aceleracion + aceleracion;
}

int Personaje::getAceleracion() 
{
    return _aceleracion;
}