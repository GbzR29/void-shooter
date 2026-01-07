#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "../system/resource_manager.h"

class Entity {

public:

	Entity() = default;
	virtual ~Entity() = default;

	//optional
	virtual void handleInput(const sf::Event& ev) {} 

	//mandatory
	virtual void update(float dt) = 0; 
	virtual void draw(sf::RenderWindow& window) const = 0;

	bool isAlive() const { return alive; }

	void kill() { alive = false; }	

protected:

	bool alive = true;
	
};

