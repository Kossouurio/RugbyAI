#pragma once
#include "Action.h"
#include "Player.h"


class PlayerAction_Idle : public Action<Player>
{
public:
	void Start(Player* pPlayer) override {};
	void Update(Player* pPlayer) override {};
	void End(Player* pPlayer) override {};
};

class PlayerAction_Attacking : public Action<Player>
{
	float mAttackTimer = 0.0f;

public:
	void Start(Player* pPlayer) override;
	void Update(Player* pPlayer) override;
	void End(Player* pPlayer) override;
	friend Player;
};

class PlayerAction_Defending : public Action<Player>
{
public:
	void Start(Player* pPlayer) override;
	void Update(Player* pPlayer) override;
	void End(Player* pPlayer) override;
	friend Player;
};

class PlayerAction_Throwing : public Action<Player>
{
	float mThrowTimer = 0.0f;

public:
	void Start(Player* pPlayer) override;
	void Update(Player* pPlayer) override;
	void End(Player* pPlayer) override;
};

