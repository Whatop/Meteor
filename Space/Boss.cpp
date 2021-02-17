#include "stdafx.h"
#include "Boss.h"
#include "Bosss.h"
#include "BossBullet.h"
#include "BossBullet2.h"
#include <stdlib.h>
#include <time.h>
#include "Enemy.h"
#include "END.h"


Boss::Boss() : move(false) //»Ç¾²
{
	Speed = 10;
	Hp = 50;
	m_Boss = Sprite::Create(L"Painting/Enemy0.png");
	m_Boss->SetParent(this);

	SetPosition(1700, 800 / 2);
	
}

Boss::~Boss()
{
}

	void Boss::Update(float deltaTime, float time)
	{
		if (Hp <= 50 && Hp >= 35) {
			if (move == false)
			{
				Speed = 15.f;
				m_Position.y -= Speed;
			}

			if (m_Position.y <= 10)
			{
				Speed = 15.f;
				move = true;
			}

			if (move)
			{
				m_Position.y += Speed;
				if (num <= 10)
				{
					if (num % 10 == 0)
						ObjectMgr::GetInst()->KeepObject(new BossBullet(m_Position),"ya");
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
		}

		if (Hp >= 10 && Hp < 35) {
			if (move == false)
			{
				Speed = 30.f;
				m_Position.y -= Speed;
			}


			if (m_Position.y <= 10)
			{
				Speed = 30.f;
				move = true;
			}

			if (move)
			{
				m_Position.y += Speed;
				if (num <= 1)
				{
					if (num % 1 == 0)
						ObjectMgr::GetInst()->KeepObject(new BossBullet2(m_Position), "A");
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

		}
		if (Hp <= 0)
		{
			SceneDirector::GetInst()->ChangeScene(new END());
		}

	}


	

		void Boss::Render()
		{

			m_Boss->Render();
		}

		void Boss::OnCollision(Object * other)
		{
			Hp--;
		}
