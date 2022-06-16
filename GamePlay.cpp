#include "GamePlay.h"

void GamePlay::aceleracion(Personaje repartidor)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (repartidor.getAceleracion() < 12)
        {
            repartidor.setAceleracion(1);
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (repartidor.getAceleracion() > 6)
        {
            repartidor.setAceleracion(-1);
        }
    }

    int velocidad = gamePlay.aceleracion(personaje);
    image.move(0, velocidad);
    if (image.getPosition().y > 0) {
        image.setPosition(image.getPosition().x, -600);
    }
}
