#include "stdafx.h"
#include "RBullet.h"
#include "Boom.h"

RBullet::RBullet(Vec2 Pos,float r)
{
	m_Speed = 15.5f;

	m_Bullet = Sprite::Create(L"Painting/PlayerBullet/0.png");
	m_Bullet->SetParent(this);
	SetPosition(Pos);

	m_Rotation = r;
}
            
RBullet::~RBullet()
{
}

void RBullet::Update(float time)
{
	Ogr->CollideCheak(this, "Monster");
	Ogr->CollideCheak(this, "Meteor");
	Vec2 vCameraPos = SIngletonC::GetInst()->GetPosition();
	if (m_Position.x + vCameraPos.x >= 1920)
	{
		ObjectMgr::GetInst()->RemoveObject(this);
	}


	Move(time);
}

void RBullet::Render()
{
	m_Bullet->Render();
}

void RBullet::Move(float time)
{
	m_Position.x += 30;
}

void RBullet::OnCollision(Object* obj, std::string tag)
{ 
	if (tag == "Monster" || tag == "Meteor")
	{
		Ogr->RemoveObject(this);
	}

}

