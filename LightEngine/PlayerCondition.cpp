#include "PlayerCondition.h"
#include "GameScene2.h"

bool PlayerCondition_HasBall::OnTest(Player* pPlayer)
{
	return pPlayer->HasBall();
}