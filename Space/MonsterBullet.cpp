#include "stdafx.h"
#include "MonsterBullet.h"
#include "Boom.h"

MonsterBullet::MonsterBullet(Vec2 Pos, int Type)
{
	m_Speed = 5.f;

	m_Bullet = Sprite::Create(L"Painting/MonsterBullet/2.png");
	m_Bullet->SetParent(this);

	SetPosition(Pos);
	m_Type = Type;
}

MonsterBullet::~MonsterBullet()
{
}

void MonsterBullet::Update( float time)
{
	Ogr->CollideCheak(this, "Player");
	Ogr->CollideCheak(this, "Meteor");
	Ogr->CollideCheak(this, "Shield");


	switch (m_Type)
	{
	case 1:
		m_Position.x -= m_Speed;

		if (m_Position.x <= 0)
		{
			ObjectMgr::GetInst()->RemoveObject(this);
		}
		break;
	case 2:
		m_Position.x += m_Speed;

		if (m_Position.x >= 1080)
		{
			ObjectMgr::GetInst()->RemoveObject(this);
		}
		break;
	case 3:
		m_Position.y -= m_Speed;

		if (m_Position.y <= 0)
		{
			ObjectMgr::GetInst()->RemoveObject(this);
		}
		break;
	case 4:
		m_Position.y += m_Speed;

		if (m_Position.y >= 1080)
		{
			ObjectMgr::GetInst()->RemoveObject(this);
		}
		break;
	case 5:
		m_Position.x -= m_Speed;
		m_Position.y += m_Speed;
		//왼쪽 밑 대각선
		if (m_Position.y >= 1080)
		{
			ObjectMgr::GetInst()->RemoveObject(this);
		}
		break;
	case 6:
		m_Position.x -= m_Speed;
		m_Position.y -= m_Speed;
		//왼쪽 위 대각선
		if (m_Position.y <= 0)
		{
			ObjectMgr::GetInst()->RemoveObject(this);
		}
		break;
	case 7:
		m_Position.x += m_Speed;
		m_Position.y += m_Speed;
		//오른쪽 아래 대각선
		if (m_Position.y >= 1080)
		{
			ObjectMgr::GetInst()->RemoveObject(this);
		}
		break;
	case 8:
		m_Position.x += m_Speed;
		m_Position.y -= m_Speed;
		//오른쪽 위 대각선
		if (m_Position.y <= 0)
		{
			ObjectMgr::GetInst()->RemoveObject(this);
		}
		break;
	}
}

void MonsterBullet::Render()
{
	m_Bullet->Render();
}

void MonsterBullet::OnCollision(Object* other, std::string tag)
{
	if (tag == "Player" || tag == "Meteor" || tag == "Shield")

	{
		Ogr->RemoveObject(this);
	}
}
