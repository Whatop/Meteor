#include "stdafx.h"
#include "Meteor.h"
#include "MMeteor.h"
#include "StageTwo.h"
#include "END.h"

Meteor::Meteor(Vec2 Pos, float rotation) : m_Hp(1000)
{
	m_BMeteor = Sprite::Create(L"Painting/Attack/Meteor/Big/2.png");
	m_BMeteor->SetParent(this);
	SetPosition(Pos);

	m_Rotation = rotation;

	m_Speed = 2.5f;
}

Meteor::~Meteor()
{
}

void Meteor::Update(float time)
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


	
	if (m_Hp <= 0)
	{
		Ogr->RemoveObject(this);
		Vec2 A, B;
		A.x = m_Position.x;
		A.y = 1000;
		B.x = m_Position.x;
		B.y = 200;
		//Ogr->KeepObject(new MMeteor(A, m_Rotation), "Meteor");
		//Ogr->KeepObject(new MMeteor(B, m_Rotation), "Meteor");
		SCENE->ChangeScene(new END());
	}
	if (m_Position.x == 0)
		Ogr->RemoveObject(this);


	Move(time);
}

void Meteor::Render()
{
	m_BMeteor->Render();
	m_BMeteor->R = 255;
	m_BMeteor->B = 255;
	m_BMeteor->G = 255;
}

void Meteor::Move(float time)
{
	m_Position.x -= m_Speed;
}

void Meteor::OnCollision(Object* obj, std::string tag)
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

	m_BMeteor->R = 255;
	m_BMeteor->G = 0;
	m_BMeteor->B = 4;
}
