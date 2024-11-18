#include "PlayerAction.h"
#include "Player.h"

#include "GameManager.h"
#include "GameScene2.h"

void PlayerAction_Attacking::Start(Player* pPlayer)
{
	mAttackTimer = pPlayer->mInvincibilityDuration;
}

void PlayerAction_Attacking::Update(Player* pPlayer)
{
	mAttackTimer += GameManager::Get()->GetDeltaTime();

	if (mAttackTimer < pPlayer->mInvincibilityDuration)
		return;

	pPlayer->mIsInvincible = false;
}

void PlayerAction_Attacking::End(Player* pPlayer) {}

void PlayerAction_Defending::Start(Player* pPlayer)
{
	pPlayer->mIsInvincible = true;
}

void PlayerAction_Defending::Update(Player* pPlayer) {}

void PlayerAction_Defending::End(Player* pPlayer)
{
	pPlayer->mIsInvincible = false;
}

//void PlayerAction_Throwing::Start(Player* pPlayer)
//{
//	mThrowTimer = pPlayer->mThrowCadence;
//}
//
//void PlayerAction_Throwing::Update(Player* pPlayer)
//{
//	mThrowTimer += GameManager::Get()->GetDeltaTime();
//
//	if (mThrowTimer < pPlayer->mThrowCadence)
//		return;
//
//	mThrowTimer -= pPlayer->mThrowCadence;
//
//	GameScene2* pScene = pPlayer->GetScene<GameScene2>();
//
//	const sf::Vector2f& position = pPlayer->GetPosition();
//
//	pPlayer->mHasBall = false;
//}

void PlayerAction_Throwing::End(Player* pPlayer) {}

