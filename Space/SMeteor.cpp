#include "stdafx.h"
#include "Player.h"
#include "SMeteor.h"
SMeteor::SMeteor(Vec2 Pos, float rotation) : m_Hp(20)
{
	
	m_SMeteor = Sprite::Create(L"Painting/Attack/Meteor/Small/1.png");
	m_SMeteor->SetParent(this);
	SetPosition(Pos);
	m_Rotation = rotation;

	Vec2 A, B;
	A = m_Position;
	B = ((Player*)Ogr->m_Objects.front())->m_Position;
	A -= B;
	D3DXVec2Normalize(&m_Dir, &A);
	m_Speed = 3.1f;
}

SMeteor::~SMeteor()
{
}

void SMeteor::Update(float time)
{
	printf("%f\n", m_Position.x);
	printf("%f\n", m_Position.y);
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
		Ogr->RemoveObject(this);
	}
	if (m_Position.x == 0)
		Ogr->RemoveObject(this);


	Move(time);
}

void SMeteor::Render()
{
	m_SMeteor->Render();

}
void SMeteor::Move(float time)
{
	Translate(-m_Dir.x * m_Speed, -m_Dir.y * m_Speed);

}

void SMeteor::OnCollision(Object* obj, std::string tag)
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

	m_SMeteor->R = 255;
	m_SMeteor->G = 21;
	m_SMeteor->B = 4;
}
