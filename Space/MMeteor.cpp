#include "stdafx.h"
#include "MMeteor.h"
#include "SMeteor.h"
MMeteor::MMeteor(Vec2 Pos, float rotation) : m_Hp(20)
{
	//Move 가 필요 없긴한대.. 흐음..
	m_MMeteor = Sprite::Create(L"Painting/Attack/Meteor/Medium/2.png");
	m_MMeteor->SetParent(this);
	SetPosition(Pos);

	m_Rotation = rotation;

	m_Speed = 1.6f;
}

MMeteor::~MMeteor()
{
}

void MMeteor::Update(float time)
{
	Ogr->CollideCheak(this, "MonsterBullet");
	Ogr->CollideCheak(this, "Bullet");
	Ogr->CollideCheak(this, "Bullet2");
	Ogr->CollideCheak(this, "Bullet3");
	Ogr->CollideCheak(this, "Bullet4");
	Ogr->CollideCheak(this, "Bullet5");

	Ogr->CollideCheak(this, "SBullet");
	Ogr->CollideCheak(this, "SBullet2");
	Ogr->CollideCheak(this, "SBullet3");
	Ogr->CollideCheak(this, "SBullet4");
	Ogr->CollideCheak(this, "SBullet5");

	if (m_Hp == 0)
	{
		Vec2 A, B;
		A.x = m_Position.x;
		A.y = m_Position.y + 100;
		B.x = m_Position.x;
		B.y = m_Position.y-100;
		Ogr->KeepObject(new SMeteor(m_Position, m_Rotation), "Meteor");
		Ogr->KeepObject(new SMeteor(B, m_Rotation-10), "Meteor");
		Ogr->KeepObject(new SMeteor(A, m_Rotation-10), "Meteor");

		Ogr->RemoveObject(this);
	}
	if (m_Position.x == 0)
		Ogr->RemoveObject(this);


	Move(time);
}

void MMeteor::Render()
{
	m_MMeteor->Render();
}

void MMeteor::Move(float time)
{
	m_Position.x -= m_Speed;
}

void MMeteor::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Bullet")
		m_Hp -= 5;
	if (tag == "Bullet2")
		m_Hp -= 6;
	if (tag == "Bullet3")
		m_Hp -= 7.2f;
	if (tag == "Bullet4")
		m_Hp -= 8.64f;
	if (tag == "Bullet5")
		m_Hp -= 10.368f;


	if (tag == "SBullet")
		m_Hp -= 2;
	if (tag == "SBullet2")
		m_Hp -= 2.4;
	if (tag == "SBullet3")
		m_Hp -= 2.88;
	if (tag == "SBullet4")
		m_Hp -= 3.456;
	if (tag == "SBullet5")
		m_Hp -= 4.1472;
	if (tag == "Meteor")
		m_Hp -= 0.5f;

	m_MMeteor->R = 255;
	m_MMeteor->G = 21;
	m_MMeteor->B = 4;
}

