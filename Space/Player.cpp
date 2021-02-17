#include "stdafx.h"  //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "Bullet.h"
#include "RBullet.h"
#include "Boom.h"
#include "Shield.h"
#include "Meteor.h"
#include "Player.h"
#include "DeathStage.h"
#include "SIngletonC.h"
#include "SceneMain.h"
#include "StageOne.h"
#include "StageTwo.h"
#include "Level_Item.h"
#include "Hill.h"
#include "ResetSkill.h"
#include "BoomEffect.h"

Player::Player() :
	HP(100),
	MaxHP(100),
	Speed(10),
	GunDelay(1),
	RDelay(0.4f),
	GDelay(0),
	SDelay(0),
	num(0),
	MaxExp(100),
	m_Exp(0),
	WeaponsKey1(true),
	WeaponsKey2(false),
	m_Shield(false),
	m_Boom(false),
	invincibility(false),
	m_Atk(false),
	AtkCheck(false),
	AlphaCheck(false),
	CameraBoss(false),
	m_Bgm(false),
	m_Skill(true),
	m_Boom1(true),
	m_Boom2(false)
{ 
	ExpMgr::GetInst()->ResetExp();
	ExpMgr::GetInst()->ResetLevel();
	m_Player = Sprite::Create(L"Painting/v-yellow.png");
	m_Player->SetParent(this);
	SetPosition(340, 540);	
	ExpMgr::GetInst()->AddLevel(1);

}

Player::~Player()
{
	
}

void Player::Update(float time)
{
	//printf("%f\n", time);
	if (invincibility == false)
	{
		Ogr->CollideCheak(this, "Monster");
		Ogr->CollideCheak(this, "MonsterBullet");
		Ogr->CollideCheak(this, "Meteor");
	}
		m_Exp = ExpMgr::GetInst()->GetExp();
		m_Level = ExpMgr::GetInst()->GetLevel();
	
	static float AtkTime = time;

	if ((SceneDirector::GetInst()->m_Stage == Stage::STAGEONE || SceneDirector::GetInst()->m_Stage == Stage::STAGETWO))
	{
		SIngletonC::GetInst()->SetPosition(Vec2(m_Position.x - 250, 0.f));
	}
	if (SceneDirector::GetInst()->m_Stage == Stage::BOSS)
	{
		SIngletonC::GetInst()->SetPosition(Vec2(2550.f, 0.f));
	}
	if (m_Position.x >= 2550 && m_Position.x <= 4470 && CameraBoss == false)
	{
		SceneDirector::GetInst()->m_Stage = Stage::BOSS;
		CameraBoss = true;
	}
	if (m_Position.x >= 7000 && m_Position.x <= 10000 && CameraBoss == true)
	{
		SceneDirector::GetInst()->m_Stage = Stage::BOSS;
		CameraBoss = false;
	} 
	if (m_Atk == true)
	{
		if (AtkCheck == false)
		{
			AtkCheck = true;
			AtkTime = time;
		}

		if (time - AtkTime >= 0.1f)
		{
			m_Atk = false;
			AtkCheck = false;
			AtkTime = time;
			m_Player->R = 255;
			m_Player->G = 255;
			m_Player->B = 255;
		}
	}
	Vec2 vCameraPos = SIngletonC::GetInst()->GetPosition();


	if (HP <= 0)
	{
		SceneDirector::GetInst()->ChangeScene(new DeathStage());
	}
	Level(time);
	Move(time);
	Shot(time);

}


void Player::Level(float time)
{
	static float BgmTime = time;
	if (m_Level == 1 && m_Exp >= MaxExp)
	{
		HP = MaxHP + (MaxHP * 0.2);
		MaxHP = HP;
		RDelay -= RDelay * 0.2;
		GunDelay -= GunDelay * 0.2;

		MaxExp = 200;

		ExpMgr::GetInst()->AddLevel(1);
		ExpMgr::GetInst()->ResetExp();
		SoundMgr::GetInst()->Stop();

		if (time - BgmTime >= 3)
		{
			SoundMgr::GetInst()->Play(L"LevelUp.wav", false);
		}
	}
	if (m_Level == 2 && m_Exp >= MaxExp)
	{
		HP = MaxHP + (MaxHP * 0.2);
		MaxHP = HP;
		RDelay -= RDelay * 0.2;
		GunDelay -= GunDelay * 0.2;

		m_Shield = true;
		MaxExp = 400;
		ExpMgr::GetInst()->AddLevel(1);
		ExpMgr::GetInst()->ResetExp();
		SoundMgr::GetInst()->Stop();

		Ogr->KeepObject(new EffectMgr(L"Painting/3/Effect/Potion/", 0, 2, 23, m_Position), "Effect");
		if (time - BgmTime >= 3)
		{
			SoundMgr::GetInst()->Play(L"LevelUp.wav", false);
			BgmTime = time;
		}

	}
	if (m_Level == 3 && m_Exp >= MaxExp)
	{
		HP = MaxHP + (MaxHP * 0.2);
		MaxHP = HP;
		RDelay -= RDelay * 0.2;
		GunDelay -= GunDelay * 0.2;

		MaxExp = 500;
		ExpMgr::GetInst()->AddLevel(1);
		ExpMgr::GetInst()->ResetExp();

		SoundMgr::GetInst()->Stop();
		if (time - BgmTime >= 3)
		{
			SoundMgr::GetInst()->Play(L"LevelUp.wav", false);
			BgmTime = time;

		}
		Ogr->KeepObject(new EffectMgr(L"Painting/3/Effect/Potion/", 0, 2, 23, m_Position), "Effect");
	}
	if (m_Level == 4 && m_Exp >= MaxExp)
	{

		HP = MaxHP + (MaxHP * 0.2);
		MaxHP = HP;
		RDelay -= RDelay * 0.2;
		GunDelay -= GunDelay * 0.2;

		m_Boom = true;
		MaxExp = 500;
		ExpMgr::GetInst()->AddLevel(1);
		ExpMgr::GetInst()->ResetExp();
		SoundMgr::GetInst()->Stop();
		if (time - BgmTime >= 3)
		{
			SoundMgr::GetInst()->Play(L"LevelUp.wav", false);
			BgmTime = time;

		}
		Ogr->KeepObject(new EffectMgr(L"Painting/3/Effect/Potion/", 0, 2, 23, m_Position), "Effect");

	}
}
void Player::Move(float time)
{
	Vec2 vCameraPos = SIngletonC::GetInst()->GetPosition();
	static float SkillTime1 = time;
	static float SkillTime2 = time;
	if (INPUT->GetKey(VK_UP) == KeyState::PRESS && m_Position.y >= 0)
	{
		m_Position.y -= Speed;
	}
	if (INPUT->GetKey(VK_DOWN) == KeyState::PRESS && m_Position.y <= 1080)
	{
		m_Position.y += Speed;
	}
	if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS && m_Position.x <= 9900)
	{
		m_Position.x += Speed;
		if (!(SceneDirector::GetInst()->m_Stage == Stage::NONE))
		{
			vCameraPos.x += Speed;
		}
		printf("%f", m_Position.x);
		// 2550 x 좌표 카메라 설정
	}
	if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS && m_Position.x >= 0)
	{
		m_Position.x -= Speed;
		if (!(SceneDirector::GetInst()->m_Stage == Stage::NONE))
		{
			vCameraPos.x -= Speed;
		}
		//printf("%f", m_Position.x);

	}
	if (INPUT->GetKey(VK_F1) == KeyState::DOWN)
	{
		if (invincibility == true)
		{
			invincibility = false;
		}
		else
		{
			invincibility = true;
		}
	}
	if (INPUT->GetKey(VK_F2) == KeyState::DOWN && m_Level < 5)
	{
		ExpMgr::GetInst()->AddExp(500);
	}

	if (INPUT->GetKey(VK_F3) == KeyState::DOWN)
	{
		int random = rand() % 3 + 1;
		Vec2 A;
		A.x = m_Position.x + 500;
		A.y = m_Position.y;

		if (random == 1 && m_Level < 5)
		{
			Ogr->KeepObject(new Level_Item(A), "LevelUp");

		}
		if (random == 2)
		{
			Ogr->KeepObject(new Hill(A), "Item_Hill");

		}
		if (random == 3)
		{
			Ogr->KeepObject(new ResetSkill(A), "ResetSkill");
		}
	}
	if (INPUT->GetKey(VK_F4) == KeyState::DOWN)
	{
		SCENE->ChangeScene(new SceneMain());
	}
	if (INPUT->GetKey(VK_F5) == KeyState::DOWN && !(SceneDirector::GetInst()->m_Stage == Stage::STAGEONE))
	{
		SCENE->ChangeScene(new StageOne());
	}
	if (INPUT->GetKey(VK_F6) == KeyState::DOWN && !(SceneDirector::GetInst()->m_Stage == Stage::STAGETWO))
	{
		SCENE->ChangeScene(new StageTwo());
	}
	if (INPUT->GetKey(VK_F7) == KeyState::DOWN)
	{
		SceneDirector::GetInst()->ChangeScene(new DeathStage());
	}
	if (INPUT->GetKey('1') == KeyState::DOWN)
	{
		if (WeaponsKey1 == false && WeaponsKey2 == true)
		{
			WeaponsKey1 = true;
			WeaponsKey2 = false;
		}
		else
		{
			WeaponsKey1 = false;
			WeaponsKey2 = true;
		}
	}
	if (INPUT->GetKey('2') == KeyState::DOWN)
	{
		if (m_Boom1 == false && m_Boom2 == true)
		{
			m_Boom1 = true;
			m_Boom2 = false;
		}
		else
		{
			m_Boom1 = false;
			m_Boom2 = true;
		}
	}
	if (INPUT->GetKey('E') == KeyState::PRESS && time - SkillTime1 >= SDelay && m_Shield == true && m_Skill == true)
	{
		Ogr->KeepObject(new Shield(m_Position), "Shield");
		SDelay = 10;
		SkillTime1 = time;
	}
	else if (INPUT->GetKey('E') == KeyState::PRESS && !(time - SkillTime1 >= SDelay) && m_Skill == true)
	{
		m_Skill = false;

	}
	else if (!(time - SkillTime1 >= SDelay))
	{
		Cool_Time1 = false;
	}
	else if (time - SkillTime1 >= SDelay)
	{
		Cool_Time1 = true;
	}
	if (INPUT->GetKey('Q') == KeyState::PRESS && time - SkillTime2 >= GDelay && m_Boom == true && m_Skill ==true && m_Boom1 == true)
	{
		Ogr->KeepObject(new Boom(m_Position,1), "Boom"); 

		GDelay = 20;
		SkillTime2 = time;
		m_Skill = false;

	}
	if (INPUT->GetKey('Q') == KeyState::PRESS && time - SkillTime2 >= GDelay && m_Boom == true && m_Skill == true && m_Boom2 == true)
	{
		Ogr->KeepObject(new Boom(m_Position, 2), "Boom");

		GDelay = 20;
		SkillTime2 = time;
		m_Skill = false;

	}
	else if (INPUT->GetKey('Q') == KeyState::PRESS && !(time - SkillTime2 >= GDelay) && m_Skill == true)
	{
		m_Skill = false;
	}
	else if(!(time - SkillTime2 >= GDelay))
	{
		Cool_Time2 = false;
	}
	else if (time - SkillTime2 >= GDelay)
	{
		Cool_Time2 = true;
	}
}
void Player::Shot(float time)
{
	static float StartTime = time;
	if (INPUT->GetKey('A') == KeyState::PRESS && time - StartTime >= RDelay && WeaponsKey1 == true)
	{
		switch (m_Level)
		{
		case 1:
			Ogr->KeepObject(new RBullet(m_Position, m_Rotation), "Bullet");
			break;
		case 2:
			Ogr->KeepObject(new RBullet(m_Position, m_Rotation), "Bullet2");
			break;
		case 3:
			Ogr->KeepObject(new RBullet(m_Position, m_Rotation), "Bullet3");
			break;;
		case 4:
			Ogr->KeepObject(new RBullet(m_Position, m_Rotation), "Bullet4");
			break;
		case 5:
			Ogr->KeepObject(new RBullet(m_Position, m_Rotation), "Bullet5");
			break;
		}


		StartTime = time;
	}

	if (INPUT->GetKey('A') == KeyState::PRESS && time - StartTime >= GunDelay && WeaponsKey2 == true)
	{
		switch (m_Level)
		{
		case 1:
			Ogr->KeepObject(new Bullet(m_Position, 1), "SBullet");
			Ogr->KeepObject(new Bullet(m_Position, 2), "SBullet");
			Ogr->KeepObject(new Bullet(m_Position, 3), "SBullet");
			Ogr->KeepObject(new Bullet(m_Position, 4), "SBullet");
			Ogr->KeepObject(new Bullet(m_Position, 5), "SBullet");
			break;
		case 2:
			Ogr->KeepObject(new Bullet(m_Position, 1), "SBullet2");
			Ogr->KeepObject(new Bullet(m_Position, 2), "SBullet2");
			Ogr->KeepObject(new Bullet(m_Position, 3), "SBullet2");
			Ogr->KeepObject(new Bullet(m_Position, 4), "SBullet2");
			Ogr->KeepObject(new Bullet(m_Position, 5), "SBullet2");

			break;

		case 3:
			Ogr->KeepObject(new Bullet(m_Position, 1), "SBullet3");
			Ogr->KeepObject(new Bullet(m_Position, 2), "SBullet3");
			Ogr->KeepObject(new Bullet(m_Position, 3), "SBullet3");
			Ogr->KeepObject(new Bullet(m_Position, 4), "SBullet3");
			Ogr->KeepObject(new Bullet(m_Position, 5), "SBullet3");

			break;
		case 4:
			Ogr->KeepObject(new Bullet(m_Position, 1), "SBullet4");	
			Ogr->KeepObject(new Bullet(m_Position, 2), "SBullet4");
			Ogr->KeepObject(new Bullet(m_Position, 3), "SBullet4");
			Ogr->KeepObject(new Bullet(m_Position, 4), "SBullet4");
			Ogr->KeepObject(new Bullet(m_Position, 5), "SBullet4");
			break;
		case 5:
			Ogr->KeepObject(new Bullet(m_Position, 1), "SBullet5");
			Ogr->KeepObject(new Bullet(m_Position, 2), "SBullet5");
			Ogr->KeepObject(new Bullet(m_Position, 3), "SBullet5");
			Ogr->KeepObject(new Bullet(m_Position, 4), "SBullet5");
			Ogr->KeepObject(new Bullet(m_Position, 5), "SBullet5");
			break;
		}


		StartTime = time;
	}

}

void Player::Render()
{
	if (!(SceneDirector::GetInst()->m_Stage == Stage::NONE))
	{
		Vec2 vCameraPos = SIngletonC::GetInst()->GetPosition();
		if (num == 0)
			m_PlayerState = Sprite::Create(L"Painting/Player/Player.png");
		if (num == 1)
			m_PlayerState = Sprite::Create(L"Painting/Player/Player2.png");
		if (num == 2)
			m_PlayerState = Sprite::Create(L"Painting/Player/Player3.png");

		m_PlayerState->SetPosition(102.5f - vCameraPos.x, +1020);
		m_PlayerState->Render();

		if (WeaponsKey1 == true)
			m_Weapon = Sprite::Create(L"Painting/Player/GunState1.png");
		if (WeaponsKey2 == true)
			m_Weapon = Sprite::Create(L"Painting/Player/GunState2.png");

		if (m_Boom == true)
			m_spBoom = Sprite::Create(L"Painting/BombSprite.png");
	
		if (m_Shield == true)
			m_spShield = Sprite::Create(L"Painting/Shield.png");
		
		if (m_Shield == false)
			m_spShield = Sprite::Create(L"Painting/Shield2.png");

		if (m_Boom == false)
			m_spBoom = Sprite::Create(L"Painting/Shield2.png");

		m_Weapon->SetPosition(430.5f - vCameraPos.x, +1015);
		m_Weapon->Render();

		m_spShield->SetPosition(630.5f - vCameraPos.x, +1015);
		m_spShield->Render();

		m_spBoom->SetPosition(830.5f - vCameraPos.x, +1015);
		m_spBoom->Render();


		TCHAR szMaxExp[32] = L"";
		TCHAR szHp[32] = L"";
		TCHAR szExp[32] = L"";
		TCHAR szLeval[32] = L"";
		TCHAR szSkill [32] = L"";
		TCHAR szCool_Time1 [32] = L"";
		TCHAR szCool_Time2[32] = L"";
		TCHAR Boom_Type[32] = L"";

		int m_Hp = 0;
		int m_Level_ = 0;
		int Exp = 0;
		int m_MaxExp = 0;
		m_Hp = HP;
		m_MaxExp = MaxExp;
		Exp = ExpMgr::GetInst()->GetExp();
		m_Level_ = m_Level;


		wsprintf(szExp, L"Exp : %d   /", Exp);
		wsprintf(szMaxExp, L"%d", m_MaxExp);
		wsprintf(szHp, L"HP : %d", m_Hp);
		wsprintf(szLeval, L"LV : %d", m_Level_);
		if (Cool_Time1 == true && m_Shield)
		{
			wsprintf(szCool_Time1, L"-- 준비완료 -- ");
		}
		if (Cool_Time1 == false && m_Shield)
		{
			wsprintf(szCool_Time1, L" -- 준비중 -- ");
		}
		if (Cool_Time2 == true && m_Boom)
		{
			wsprintf(szCool_Time2, L"-- 준비완료 -- ");
		}
		if (Cool_Time2 == false && m_Boom)
		{
			wsprintf(szCool_Time2, L" -- 준비중 -- ");
		}
		if (m_Boom1 == true && m_Boom)
		{
			wsprintf(Boom_Type, L" --투하-- ");
		}
		if (m_Boom2 == true && m_Boom)
		{
			wsprintf(Boom_Type, L" --투척-- ");
		}
		if (m_Skill == false)
		{
			wsprintf(szSkill, L" 아직 사용할 수 없습니다. ");
			m_Skill = true;
		}
		Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
		Matrix matFont;

		D3DXMatrixTranslation(&matFont, 1750 + 40, 30, 0);
		Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
		Renderer::GetInst()->GetBulletFont()->DrawTextW(Renderer::GetInst()->GetSprite(),
			szMaxExp, 32, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 0));

		D3DXMatrixTranslation(&matFont, 1600 - 80, 30, 0);
		Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
		Renderer::GetInst()->GetBulletFont()->DrawTextW(Renderer::GetInst()->GetSprite(),
			szExp, 32, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 0));

		D3DXMatrixTranslation(&matFont, 300 - 10, 30, 0);
		Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
		Renderer::GetInst()->GetBulletFont()->DrawTextW(Renderer::GetInst()->GetSprite(),
			szHp, 32, NULL, NULL, D3DCOLOR_ARGB(255, 255, 0, 0));

		D3DXMatrixTranslation(&matFont, 120 - 10, 30, 0);
		Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
		Renderer::GetInst()->GetBulletFont()->DrawTextW(Renderer::GetInst()->GetSprite(),
			szLeval, 32, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 0));
		D3DXMatrixTranslation(&matFont, 500 - 10, 850, 0);
		Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
		Renderer::GetInst()->GetBulletFont()->DrawTextW(Renderer::GetInst()->GetSprite(),
			szSkill, 32, NULL, NULL, D3DCOLOR_ARGB(130, 255, 0, 0));

		D3DXMatrixTranslation(&matFont, 570 - 10, 934, 0);
		Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
		Renderer::GetInst()->GetMonsterFont()->DrawTextW(Renderer::GetInst()->GetSprite(),
			szCool_Time1, 32, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 0));

		D3DXMatrixTranslation(&matFont, 770 - 10, 935, 0);
		Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
		Renderer::GetInst()->GetMonsterFont()->DrawTextW(Renderer::GetInst()->GetSprite(),
			szCool_Time2, 32, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 0));

		D3DXMatrixTranslation(&matFont, 787 - 10, 910, 0);
		Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
		Renderer::GetInst()->GetMonsterFont()->DrawTextW(Renderer::GetInst()->GetSprite(),
			Boom_Type, 32, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 0));
		Renderer::GetInst()->GetSprite()->End();

		SetRect(&m_Collision, m_Position.x - m_Size.x / 2, m_Position.y - m_Size.x / 2, m_Position.x + m_Size.x / 2, m_Position.y + m_Size.x / 2);

		//InitProgram();
		//Draw();
		m_Player->Render();

	}
	if ((SceneDirector::GetInst()->m_Stage == Stage::NONE))
	{
		m_Player->Render();
	}

}

void Player::OnCollision(Object* other, std::string tag)
{
	if (tag == "Item_Hill")
	{
		HP += (MaxHP * 0.2);
		if (MaxHP < HP)
			HP = MaxHP;
	}
	if (tag == "Hill")
	{
		HP = MaxHP;
	}
	if (tag == "ResetSkill")
	{
		SDelay = 0;
		GDelay = 0;
	}
	if (tag == "LevelUp" && m_Level <= 4)
	{
		ExpMgr::GetInst()->AddExp(500);

	}
	if (tag == "MonsterBullet" && invincibility == false)
	{
		num = 1;
		m_Atk = true;
		HP -= 5;

		m_Player->R = 255;
		m_Player->G = 51;
		m_Player->B = 4;
	}
	if (tag == "Monster" && invincibility == false)
	{
		num = 1;
		m_Atk = true;
		HP -= 1;

		m_Player->R = 255;
		m_Player->G = 51;
		m_Player->B = 4;
	}
	if (tag == "Meteor" && invincibility == false)
	{
		num = 1;
		m_Atk = true;
		HP -= 1;
		m_Player->R = 255;
		m_Player->G = 51;
		m_Player->B = 4;
	}

}

void Player::Draw()
{

	Vec2 vCameraPos = SIngletonC::GetInst()->GetPosition();

	Vec2 vList[] = {
	   Vec2(m_Position.x + 25 + vCameraPos.x,m_Position.y - 32.5),
	   Vec2(m_Position.x + 25 + vCameraPos.x,m_Position.y + 32.5),
	   Vec2(m_Position.x - 25 + vCameraPos.x,m_Position.y + 32.5),
	   Vec2(m_Position.x - 25 + vCameraPos.x,m_Position.y - 32.5),
	   Vec2(m_Position.x + 25 + vCameraPos.x,m_Position.y - 32.5),
	};
	g_pLine->Begin();
	g_pLine->Draw(vList, 5, D3DCOLOR_XRGB(255, 0, 0));
}
void Player::InitProgram()
{
	LPDIRECT3DDEVICE9 pDevice = Renderer::GetInst()->GetDevice();   
	D3DXCreateLine(pDevice, &g_pLine);
	g_pLine->SetWidth(10);
}