#include <stdlib.h>
#include "GamePlay.h"

GamePlay::GamePlay()
{
}

/*void GamePlay::aceleracion(Personaje repartidor, sf::Sprite aux)
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

    int velocidad = repartidor.getAceleracion();
    
    aux.move(0, velocidad);
    if (aux.getPosition().y > 0) {
        aux.setPosition(aux.getPosition().x, -600);
    }
}
*/

void GamePlay::update()
{
    _player.update();
    _carpincho.update();
}

void GamePlay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_player, states);
    target.draw(_carpincho, states);
}
