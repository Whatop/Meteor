#include "stdafx.h"
#include "MonsterBullet2.h"
#include "Boom.h"

MonsterBullet2::MonsterBullet2(Vec2 MosterPos)
{
	m_Speed = 20.f;

	m_Bullet = Sprite::Create(L"Painting/2/Scene/GameName.png");
	m_Bullet->SetParent(this);

	SetPosition(MosterPos.x, MosterPos.y);
}
MonsterBullet2::~MonsterBullet2()
{
}

void MonsterBullet2::Update(float time)
{
	Ogr->CollideCheak(this, "Player");
	Ogr->CollideCheak(this, "Meteor");
	Ogr->CollideCheak(this, "Shield");
	m_Position.x -= m_Speed;

	if (m_Position.x <= 0)
	{
		ObjectMgr::GetInst()->RemoveObject(this);
	}
}

void MonsterBullet2::Render()
{
	m_Bullet->Render();
}

void MonsterBullet2::OnCollision(Object* other,std::string tag)
{
	if (tag == "Player" || tag == "Meteor" || tag == "Shield")
	{
		Ogr->RemoveObject(this);

	}
}

