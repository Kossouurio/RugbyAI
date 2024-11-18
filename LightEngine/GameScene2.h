#pragma once
#include "GameManager.h"

#include <list>

class Player;

namespace sf
{
	class Event;
}

class GameScene2 : public Scene
{
public:
	enum Tag
	{
		ATTACK,
		DEFENCE
	};

	int mLaneCount[3] = { 0, 0, 0 };

private:
	int GetClickedArea(int x, int y) const;

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;
};

