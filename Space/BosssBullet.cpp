#include "stdafx.h"
#include "BosssBullet.h"
BosssBullet::BosssBullet(Vec2 MosterPos)
{
	m_Speed = 13.f;

	m_Bullet = Sprite::Create(L"Painting/Attack/BossBullet1.png");
	m_Bullet->SetParent(this);

	SetPosition(MosterPos.x, MosterPos.y);
}

BosssBullet::~BosssBullet()
{
}

void BosssBullet::Update(float deltaTime, float time)
{
	m_Position.x -= m_Speed;

	if (m_Position.x <= 0)
	{
		ObjectMgr::GetInst()->RemoveObject(this);
	}
}

void BosssBullet::Render()
{
	m_Bullet->Render();
}

void BosssBullet::OnCollision(Object* other)
{
	ObjectMgr::GetInst()->RemoveObject(this);
}

