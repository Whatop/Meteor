#include "stdafx.h"
#include "Bosss.h"
#include "BosssBullet.h"
#include <stdlib.h>
#include <time.h>

Bosss::Bosss() : move(false) //»Ç¾² Àâ¸÷
{
	Hp = 10;
	m_Bosss = Sprite::Create(L"Painting/Enemy!!!.png");
	m_Bosss->SetParent(this);

	SetPosition(1800, 300);
}


Bosss::~Bosss()
{
	//ObjectMgr::GetInst()->KeepObject(new Boss1, OBJECTLIST::ENEMY);

}


void Bosss::Update(float deltaTime, float time)
{ 
	if (Hp > 0 && Hp <= 10)
	{

		if (num <= 20)
		{
			if (num % 1 == 0)
				ObjectMgr::GetInst()->KeepObject(new BosssBullet(m_Position), "AI");
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

void Bosss::Render()
{

	m_Bosss->Render();
}

void Bosss::OnCollision(Object* other)
{
	Hp--;
}
