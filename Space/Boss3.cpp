#include "stdafx.h"
#include "Boss3.h"
#include "Boss3Bullet.h"
#include <stdlib.h>
#include <time.h>

Boss3::Boss3() : move(false) //»Ç¾² Àâ¸÷
{
	Hp = 10;
	m_Boss3 = Sprite::Create(L"Painting/Enemy!!!.png");
	m_Boss3->SetParent(this);

	SetPosition(1800, 800);
}


Boss3::~Boss3()
{
	//ObjectMgr::GetInst()->KeepObject(new Boss1, OBJECTLIST::ENEMY);

}


void Boss3::Update(float deltaTime, float time)
{
	if (Hp > 0 && Hp <= 10)
	{

		if (num <= 20)
		{
			if (num % 1 == 0)
				ObjectMgr::GetInst()->KeepObject(new Boss3Bullet(m_Position), "HO");
		}

	}
	if (num >= 10)
	{
		num = 0;
	}
	num++;

	if (m_Position.y >= 1100)
	{
		move = false;
	}
	if (Hp <= 0) {
		ObjectMgr::GetInst()->RemoveObject(this);
	}
}

void Boss3::Render()
{

	m_Boss3->Render();
}

void Boss3::OnCollision(Object* other)
{
	Hp--;
}
