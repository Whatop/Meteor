#include "stdafx.h"
#include "BossBullet2.h"

BossBullet2::BossBullet2(Vec2 MosterPos)
{
	m_Speed = 20.f;

	m_Bullet = Sprite::Create(L"Painting/Attack/BossBullet2.png");
	m_Bullet->SetParent(this);

	SetPosition(MosterPos.x, MosterPos.y);
}
BossBullet2::~BossBullet2()
{
}

void BossBullet2::Update(float deltaTime, float time)
{
	m_Position.x -= m_Speed;

	if (m_Position.x <= 0)
	{
		ObjectMgr::GetInst()->RemoveObject(this);
	}
}

void BossBullet2::Render()
{
	m_Bullet->Render();
}

void BossBullet2::OnCollision(Object* other)
{
	ObjectMgr::GetInst()->RemoveObject(this);
}

