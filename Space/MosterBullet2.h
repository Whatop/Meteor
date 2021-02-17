#pragma once
#include "stdafx.h"
#include "MonsterBullet.h"

EnemyBullet::EnemyBullet(Vec2 MonsterPos)
{
	m_Speed = 20.f;

	m_Bullet = Sprite::Create(L"Painting/Attack/!Bullet.png");
	m_Bullet->SetParent(this);

	SetPosition(MonsterPos.x, MonsterPos.y);
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Update(float deltaTime, float time)
{
	m_Position.x -= m_Speed;

	if (m_Position.x <= 0)
	{
		ObjectMgr::GetInst()->RemoveObject(this);
	}
}

void EnemyBullet::Render()
{
	m_Bullet->Render();
}

void EnemyBullet::OnCollision(Object* other)
{
	ObjectMgr::GetInst()->RemoveObject(this);
}

