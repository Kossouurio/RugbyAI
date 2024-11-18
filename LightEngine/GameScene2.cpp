#include "GameScene2.h"

#include "Player.h"
#include "Debug.h"

void GameScene2::OnInitialize()
{
	int width = GetWindowWidth();
	int height = GetWindowHeight();

	float PlayerRadius = 10.f;
	float PlayerHeight = PlayerRadius * 2;
	float spaceBetweenPlayers = 20;

	float totalHeight = (spaceBetweenPlayers * 2) + (PlayerHeight * 3);
	float spacing = height - totalHeight;

	float startX = PlayerRadius * 2;
	float startY = PlayerRadius + (spacing / 2);

	Player* pPlayers[10];

	for (int i = 0; i < 5; i++)
	{
		pPlayers[i] = CreateEntity<Player>(PlayerRadius, sf::Color::Green);
		pPlayers[i]->SetPosition(startX, startY, 0.5f, 0.5f);
		pPlayers[i]->SetAreaIndex(i);

		startY += PlayerHeight + spaceBetweenPlayers;
	}
}


void GameScene2::OnUpdate()
{
	Debug::DrawLine(0, GetWindowHeight() / 3, GetWindowWidth(), GetWindowHeight() / 3, sf::Color::White);
	Debug::DrawLine(0, GetWindowHeight() / 3 * 2, GetWindowWidth(), GetWindowHeight() / 3 * 2, sf::Color::White);
}

int GameScene2::GetClickedArea(int x, int y) const
{
	if (y < (GetWindowHeight() / 3))
	{
		return 0;
	}
	else if (y > (GetWindowHeight() / 3) && y < (GetWindowHeight() / 3) * 2)
	{
		return 1;
	}
	else if (y > (GetWindowHeight() / 3) * 2)
	{
		return 2;
	}
	else
	{
		return -1;
	}
}

void GameScene2::OnEvent(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	int index = GetClickedArea(event.mouseButton.x, event.mouseButton.y);

	if (index == -1)
		return;

	mLaneCount[index]++;
}
