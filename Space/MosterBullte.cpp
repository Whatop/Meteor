#include "stdafx.h"
#include "Mons"

MonsterBullet::MonsterBullet(Vec2 MonsterPos)
{
	m_Speed = 20.f;

	m_Bullet = Sprite::Create(L"Painting/Attack/!Bullet.png");
	m_Bullet->SetParent(this);

	SetPosition(MonsterPos.x, MonsterPos.y);
}

MonsterBullet::~MonsterBullet()
{
}

void MonsterBullet::Update(float deltaTime, float time)
{
	m_Position.x -= m_Speed;

	if (m_Position.x <= 0)
	{
		ObjectMgr::GetInst()->RemoveObject(this);
	}
}

void MonsterBullet::Render()
{
	m_Bullet->Render();
}

void MonsterBullet::OnCollision(Object* other)
{
	ObjectMgr::GetInst()->RemoveObject(this);
}

