#include "player.hpp"
#include <iostream>

namespace Objects {
    Player::Player() : Creature("player", 100,100,10,25, 100) {}

    void Player::onEvent(const sf::Event &event) {
        if (event.type == sf::Event::KeyPressed) {
            std::cout << "press\n";
            if (event.key.code == sf::Keyboard::W) {
                m_velocity.y += -m_speed;
            } 
            else if (event.key.code == sf::Keyboard::A) {
                m_velocity.x += -m_speed;
            } 
            else if (event.key.code == sf::Keyboard::S) {
                m_velocity.y += m_speed;
            } 
            else if (event.key.code == sf::Keyboard::D) {
                m_velocity.x += m_speed;
            }
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::W) {
                m_velocity.y -= -m_speed;
            } 
            else if (event.key.code == sf::Keyboard::A) {
                m_velocity.x -= -m_speed;
            } 
            else if (event.key.code == sf::Keyboard::S) {
                m_velocity.y -= m_speed;
            } 
            else if (event.key.code == sf::Keyboard::D) {
                m_velocity.x -= m_speed;
            }
        }
        if (m_velocity.x > 0) {
            m_facing = RIGHT;
        } else if (m_velocity.x < 0) {
            m_facing = LEFT;
        }

        if (m_velocity.y > 0) {
            m_facing = DOWN;
        } else if (m_velocity.y < 0) {
            m_facing = UP;
        }
    }
}