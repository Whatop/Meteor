#include "stdafx.h"
#include "EnemyBullet2.h"

EnemyBullet2::EnemyBullet2(Vec2 MonsterPos)
{
	m_Speed = 3.f;

	m_Bullet = Sprite::Create(L"Painting/1/kyo/kick/9.png");
	m_Bullet->SetParent(this);

	SetPosition(MonsterPos.x, MonsterPos.y);
}

EnemyBullet2::~EnemyBullet2()
{
}

void EnemyBullet2::Update(float deltaTime, float time)
{
	m_Position.x -= m_Speed;

	if (m_Position.x <= 0)
	{
		ObjectMgr::GetInst()->RemoveObject(this);
	}

}

void EnemyBullet2::Render()
{
	m_Bullet->Render();
}

void EnemyBullet2::OnCollision(Object* other)
{
	ObjectMgr::GetInst()->RemoveObject(this);
}

