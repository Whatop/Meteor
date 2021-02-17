#include "stdafx.h"
#include "Bullet.h"
#include "Player.h"
#include "Boom.h"
Bullet::Bullet(Vec2 Pos,int type):GunDelay(0.5f)
{
	m_Bullet = Sprite::Create(L"Painting/Diee/1.png");
	m_Bullet->SetParent(this);
	m_Type = type;
	SetPosition(Pos.x, Pos.y);
}

Bullet::~Bullet()
{
}

void Bullet::Update(float time)
{
	Ogr->CollideCheak(this, "Monster");
	Ogr->CollideCheak(this, "Meteor");

	switch (m_Type)
	{
	case 1:
		m_Position.x += 30;
		m_Position.y += 2.5;
		break;
	case 2:
		m_Position.x += 30;
		m_Position.y += 1.25;
		break;
	case 3:
		m_Position.x += 30;
		m_Position.y -= 1.25;
		break;
	case 4:
		m_Position.x += 30;
		m_Position.y -= 2.5;
		break;
	case 5:
		m_Position.x += 30;
		break;
	}
	

	/*if (m_Position.x + vCameraPos.x >= 1920 || vCameraPos.x <= 0 || vCameraPos.y >= 1080 || vCameraPos.y <= 0)
	{
		ObjectMgr::GetInst()->RemoveObject(this);
	}*/
	Vec2 vCameraPos = SIngletonC::GetInst()->GetPosition();
	if (m_Position.x + vCameraPos.x >= 1920)
	{
		ObjectMgr::GetInst()->RemoveObject(this);
	}

	
}

void Bullet::Render()
{
	m_Bullet->Render();
}



void Bullet::OnCollision(Object* other,std::string tag)
{
	if(tag=="Monster" || tag == "Meteor")
	{
		Ogr->RemoveObject(this);
	}
}

