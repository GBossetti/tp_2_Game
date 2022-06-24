#include "Personaje.h"

Personaje::Personaje()
{
    _velocity = { 0,0 };
    _inmunidad = false;
	_texture.loadFromFile("repartidor.png");
	_sprite.setTexture(_texture);
    //_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
    //_sprite.setPosition(600 / 2 , 800 - _sprite.getGlobalBounds().height);
    setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
    setPosition(600 / 2, 800 - _sprite.getGlobalBounds().height);
    _aceleracion = 6;
}

void Personaje::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        move(0, -4);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        move(-4, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        move(0, 4);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        move(4, 0);
    }

    if (getBounds().left < 150) {
       setPosition(150 + getOrigin().x, getPosition().y);
    }
    if (getBounds().top < 0) {
        setPosition(getPosition().x, getOrigin().y);
    }
    if (getBounds().left + getBounds().width > 450) {
        setPosition(450 - (getBounds().width - getOrigin().x), getPosition().y);
    }
    if (getBounds().left + getBounds().width > 800) {
        setPosition(800 - (getBounds().width - getOrigin().x), getPosition().y);
    }
    if (getBounds().top + getBounds().height > 600) {
        setPosition(getPosition().x, 600 + (getBounds().height - getOrigin().y));
    }
}

void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform(); //Multiplico matriz de transformacion por la matriz de transformacion de mi objeto
    target.draw(_sprite, states);

}





sf::FloatRect Personaje::getBounds() const
{
    return getTransform().transformRect(_body.getGlobalBounds()); //Esto lo agregó Brian en la clase. Dedería agregar la propiedad _body al personaje, como tiene en el video de las naves

    //return _sprite.getGlobalBounds(); //Esta no va porque el _sprite sigue teniendo las coordenas (0,0). Debería de multiplicar _sprite tmb por la matriz .transformRect, o usar _body, como arriba
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