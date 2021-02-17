#include "stdafx.h"
#include "Boss3Bullet.h"

Boss3Bullet::Boss3Bullet(Vec2 MosterPos)
{
	m_Speed = 13.f;

	m_Bullet = Sprite::Create(L"Painting/Attack/BossBullet1.png");
	m_Bullet->SetParent(this);

	SetPosition(MosterPos.x, MosterPos.y);
}

Boss3Bullet::~Boss3Bullet()
{
}

void Boss3Bullet::Update(float deltaTime, float time)
{
	m_Position.x -= m_Speed;

	if (m_Position.x <= 0)
	{
		ObjectMgr::GetInst()->RemoveObject(this);
	}
}

void Boss3Bullet::Render()
{
	m_Bullet->Render();
}

void Boss3Bullet::OnCollision(Object* other)
{
	ObjectMgr::GetInst()->RemoveObject(this);
}

