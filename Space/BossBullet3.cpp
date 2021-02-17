#include "stdafx.h"
#include "BossBullet3.h"

BossBullet3::BossBullet3(Vec2 MosterPos)
{
	m_Speed = 20.f;

	m_Bullet = Sprite::Create(L"Painting/Attack/BossBullet3.png");
	m_Bullet->SetParent(this);

	SetPosition(MosterPos.x, MosterPos.y);
}
BossBullet3::~BossBullet3()
{
}

void BossBullet3::Update(float deltaTime, float time)
{
	m_Position.x -= m_Speed;

	if (m_Position.x <= 0)
	{
		ObjectMgr::GetInst()->RemoveObject(this);
	}
}

void BossBullet3::Render()
{
	m_Bullet->Render();
}

void BossBullet3::OnCollision(Object* other)
{
	ObjectMgr::GetInst()->RemoveObject(this);
}

