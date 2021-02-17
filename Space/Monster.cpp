#include "stdafx.h"
#include "Monster.h"
#include "MonsterBullet.h"
#include "MonsterBullet2.h"
#include "Enemy.h"
#include "Player.h"
#include "Meteor.h"
#include "Minion.h"
#include "Dog.h"
#include "Hill.h"
#include "ResetSkill.h"
#include "Level_Item.h"

Monster::Monster(Vec2 Pos) : move(false), boo(false), SpawnDelay(2)
{
	Speed = 10;
	Hp = 150;
	m_Monster = Sprite::Create(L"Painting/v-truck.png");
	m_Monster->SetParent(this);
	SetPosition(Pos);
}

Monster::~Monster()
{
}	

void Monster::Update(float time)
{

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

	Ogr->CollideCheak(this, "Player");
	Ogr->CollideCheak(this, "Meteor");
	Ogr->CollideCheak(this, "Boom");
	static float StartTime = time;

	if (Hp <= 0)
	{
		ObjectMgr::GetInst()->RemoveObject(this);
		Ogr->KeepObject(new EffectMgr(L"Painting/Die/", 1, 2, 6, m_Position), "Effect");
		SceneDirector::GetInst()->m_Stage = Stage::STAGEONE;

		int Level = ExpMgr::GetInst()->GetLevel(); 
		if (Level < 5)
		{
			ExpMgr::GetInst()->AddExp(200);
		}
		RankMgr::GetInst()->AddScore(300);
		int random = rand() % 19 + 1;

		if (random == 1 && Level < 5)
		{
			Ogr->KeepObject(new Level_Item(m_Position), "LevelUp");

		}
		if (random == 2)
		{
			Ogr->KeepObject(new Hill(m_Position), "Item_Hill");

		}
		if (random == 3 )
		{
			Ogr->KeepObject(new ResetSkill(m_Position), "ResetSkill");
		}

	}
	if (time - StartTime >= SpawnDelay)
	{
		Vec2 A;
		A = ((Player*)Ogr->m_Objects.front())->m_Position;
		int random = rand() % 1000 + m_Position.x;
		int random1 = rand() % 1079 + 1;
		Vec2 B;
		B.x = random;
		B.y = random1;

			 
				
		ObjectMgr::GetInst()->KeepObject(new Minion(B,2), "Monster");
		StartTime = time;
	}

	Object* pPlayer = nullptr;
	for (const auto& iter : ObjectMgr::GetInst()->m_Objects)
	{
		if ((iter)->m_Tag == "Player")
		{
			pPlayer = iter;
		}
	}
	//Vec2 vPlayerPos = pPlayer->m_Position;
	//ObjectMgr::GetInst()->KeepObject(new Dog(vPlayerPos.x, -100, 2), "Monster");
	//ObjectMgr::GetInst()->KeepObject(new Dog(vPlayerPos.x, 1180, 1), "Monster");
	
	if (Hp <= 150 && Hp >= 75) {
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
				{
					ObjectMgr::GetInst()->KeepObject(new MonsterBullet(m_Position,1), "MonsterBullet");
				}
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
	if (Hp <= 10 && boo == false)
	{
		boo = true;

		Vec2 A;
		A.x = m_Position.x + 1500;
		A.y = m_Position.y;
		Ogr->KeepObject(new Meteor(A, m_Rotation), "Meteor");

	}
	if (Hp <= 75 && Hp > 0) {
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
			if (num <= 20)
			{
				if (num % 10 == 0)
					ObjectMgr::GetInst()->KeepObject(new MonsterBullet2(m_Position), "MonsterBullet");
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
	//m_Monster->Update(time);
}

void Monster::Render()
{
	Vec2 vCameraPos = SIngletonC::GetInst()->GetPosition();
	//InitProgram();
	//Draw();
	TCHAR szHp[32] = L"";
	int m_Hp = Hp;
	wsprintf(szHp, L"Hp : %d", m_Hp);

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	Matrix matFont;

	D3DXMatrixTranslation(&matFont, m_Position.x + vCameraPos.x,m_Position.y -50, 0);
	Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
	Renderer::GetInst()->GetMonsterFont()->DrawTextW(Renderer::GetInst()->GetSprite(),
		szHp, 32, NULL, NULL, D3DCOLOR_ARGB(255, 255, 0, 0));
	Renderer::GetInst()->GetSprite()->End();
	m_Monster->Render();

	m_Monster->R = 255;
	m_Monster->G = 255;
	m_Monster->B = 255;

}

void Monster::OnCollision(Object* other, std::string tag)
{
	if (tag == "Bullet")
		Hp -= 5;
	if (tag == "Bullet2")
		Hp -= 6;
	if (tag == "Bullet3")
		Hp -= 7.2f;
	if (tag == "Bullet4")
		Hp -= 8.64f;
	if (tag == "Bullet5")
		Hp -= 10.368f;


	if (tag == "SBullet")
		Hp -= 2;
	if (tag == "SBullet2")
		Hp -= 2.4;
	if (tag == "SBullet3")
		Hp -= 2.88;
	if (tag == "SBullet4")
		Hp -= 3.456;
	if (tag == "SBullet5")
		Hp -= 4.1472;
	if (tag == "Meteor")
		Hp -= 0.5f;
	if (tag == "Boom")
		Hp -= 0.1f;

	m_Monster->R = 255;
	m_Monster->G = 21;
	m_Monster->B = 4;
}

void Monster::Draw()
{
	Vec2 MonsterHp[] =
	{
	Vec2(m_Position.x - 60,m_Position.y - 100),
	Vec2(m_Position.x * Hp,m_Position.y - 100),
	};
	g_pLine->Begin();
	g_pLine->Draw(MonsterHp, 2, D3DCOLOR_XRGB(255, 0, 0));
}

void Monster::InitProgram()
{
	LPDIRECT3DDEVICE9 pDevice = Renderer::GetInst()->GetDevice();
	D3DXCreateLine(pDevice, &g_pLine);
	g_pLine->SetWidth(55);
}
