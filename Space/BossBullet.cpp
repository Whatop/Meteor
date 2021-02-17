#include "stdafx.h"
#include "BossBullet.h"


BossBullet::BossBullet(Vec2 MosterPos)
{
	m_Speed = 20.f;

	m_Bullet = Sprite::Create(L"Painting/Attack/BossBullet1.png");
	m_Bullet->SetParent(this);

	SetPosition(MosterPos.x, MosterPos.y);
}

BossBullet::~BossBullet()
{
}

void BossBullet::Update(float deltaTime, float time)
{
	m_Position.x -= m_Speed;

	if (m_Position.x <= 0)
	{
		ObjectMgr::GetInst()->RemoveObject(this);
	}
}

void BossBullet::Render()
{
	m_Bullet->Render();
}

void BossBullet::OnCollision(Object* other)
{
	ObjectMgr::GetInst()->RemoveObject(this);
}

