#pragma once

#include "Entity.h"
#include "StateMachine.h"

class Player : public Entity
{
	StateMachine<Player> mStateMachine;

	enum State
	{
		Idle,
		Attacking,
		Defending,

		Count
	};

	float mSpeed = 100.0f;
	float mSpeedMultiplier = 1.0f;
	float mInvincibilityDuration = 3.0f;
	bool mIsInvincible = false;
	bool mHasBall = false;
	float mThrowCadence = 1.0f;
	int mAreaIndex;

public:
	Player(float radius, const sf::Color& color);

	void SetAreaIndex(int index) { mAreaIndex = index; }
	int GetAreaIndex() { return mAreaIndex; }
	const char* GetStateName(State state) const;
	bool HasBall() { return mHasBall; }

protected:
	void OnUpdate() override;
	void OnCollision(Entity* pCollidedWith) override;

	friend class PlayerAction_Idle;
	friend class PlayerAction_Attacking;
	friend class PlayerAction_Defending;
};

