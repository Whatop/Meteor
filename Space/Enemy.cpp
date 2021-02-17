#include "stdafx.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "EnemyBullet2.h"

Enemy::Enemy() //°Å¿ïÀÌ
{
	HP = 15;
	Speed = 17;
	EnemyBulletDelay = 0.f;
	m_Enemy = Sprite::Create(L"Painting/Enemy3.png");
	m_Enemy->SetParent(this);

	SetPosition(1800, 400);
}

Enemy::~Enemy()
{
	

}

void Enemy::Update(float deltaTime, float time)
{
	EnemyBulletDelay++;

	if (m_Position.y >= 0) {
		if (INPUT->GetKey(VK_UP) == KeyState::PRESS)
		{
			m_Position.y -= Speed;
		}
	}
	if (m_Position.y <= 1080) {
		if (INPUT->GetKey(VK_DOWN) == KeyState::PRESS)
		{
			m_Position.y += Speed;
		}
	}
	if (m_Position.x <= 1920) {
		if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS)
		{
			m_Position.x += Speed;
		}
	}
	if (m_Position.x >= 0) {
		if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS)
		{
			m_Position.x -= Speed;
		}
	}
	if (HP>10 && INPUT->GetKey(VK_SPACE) == KeyState::PRESS && EnemyBulletDelay >= 20)
	{
		ObjectMgr::GetInst()->KeepObject(new EnemyBullet(m_Position), "AI");
		EnemyBulletDelay = 0.f;
	}
	if (HP <= 10 && INPUT->GetKey(VK_SPACE) == KeyState::PRESS && EnemyBulletDelay >= 15)
	{
		ObjectMgr::GetInst()->KeepObject(new EnemyBullet2(m_Position), "AI");
		EnemyBulletDelay = 0.f;
	}
	if (HP <= 0)
	{
		ObjectMgr::GetInst()->RemoveObject(this);
	}

}

void Enemy::Render()
{
	
	m_Enemy->Render();
}
void Enemy::OnCollision(Object* other)
{
	HP--;
}



	