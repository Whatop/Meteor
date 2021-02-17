#include "stdafx.h"
#include "Boom.h"
#include "BoomEffect.h"

Boom::Boom(Vec2 Pos,int type)
{
	m_Boom = Sprite::Create(L"Painting/BombLitSprite.png");
	m_Boom->SetParent(this);
	SetPosition(Pos);

	m_Type = type;
	speed = -10;
	Speed = -20;
}
   
Boom::~Boom()
{
}


void Boom::Update(float time)
{
	Ogr->CollideCheak(this, "Monster");
	Ogr->CollideCheak(this, "Meteor");
	Vec2 vCameraPos = SIngletonC::GetInst()->GetPosition();
	switch (m_Type)
	{
	case 1:// 살포시 내리는 수류탄
		if (m_Position.y + vCameraPos.y > 1080)
		{
			ObjectMgr::GetInst()->RemoveObject(this);
			Ogr->KeepObject(new BoomEffect(m_Position), "Boom");
		}
		m_Position.x += 10;
		m_Position.y += speed;
		speed += 1;
		break;

	case 2:// 멀리 던지는 수류탄
		if (m_Position.y + vCameraPos.y > 1080)
		{
			ObjectMgr::GetInst()->RemoveObject(this);
			Ogr->KeepObject(new BoomEffect(m_Position), "Boom");
		}
		m_Position.x += 20;
		m_Position.y += Speed;
		Speed += 1;
		break;
	}
	
}

void Boom::Render()
{
	m_Boom->Render();
}

void Boom::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Monster" || tag == "Meteor")
	{
		Ogr->RemoveObject(this);
		Ogr->KeepObject(new BoomEffect(m_Position), "Boom");

	}

}

