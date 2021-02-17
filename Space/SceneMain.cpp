#include "stdafx.h"  //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "SceneMain.h"
#include "StageOne.h"
#include "Monster.h"
#include "HOW_PLAY.h"
#include "SIngletonC.h"
#include "Player.h"
#include "Meteor.h"
#include "RankScene.h"
#include "END.h"

SceneMain::SceneMain() : mm(false)
{
	SoundMgr::GetInst()->Stop();

	m_BackGround = Sprite::Create(L"Painting/Day/Background_Day/Daylight_sky.png");
	m_BackGround->SetPosition(1920 / 2, 1080 / 2);
	m_BackGround = Sprite::Create(L"Painting/splash.png");
	m_BackGround->SetPosition(1920 / 2, 300);

	m_Start = Sprite::Create(L"Painting/StartHoverSprite.png");
	m_Buttons.push_back(m_Start);
	m_Start->SetPosition(1700, 700);

	m_Exit = Sprite::Create(L"Painting/EXIT.png");
	m_Buttons.push_back(m_Exit);
	m_Exit->SetPosition(1700, 300);

	m_Help = Sprite::Create(L"Painting/HELP.png");
	m_Buttons.push_back(m_Help);
	m_Help->SetPosition(1700, 500);

	m_Rank = Sprite::Create(L"Painting/RANK.png");
	m_Buttons.push_back(m_Rank);
	m_Rank->SetPosition(1700, 900);
	SceneDirector::GetInst()->m_Stage = Stage::NONE;
	SIngletonC::GetInst()->SetPosition(Vec2(0.f, 0.f));

	SoundMgr::GetInst()->Play(L"Menu0.wav", true);

} 

SceneMain::~SceneMain()
{
	
}

void SceneMain::Update( float time)
{
	//SIngletonC::GetInst()->SetPosition(Vec2(0.f, 0.f));
	int num = 1;
	for (auto& iter : m_Buttons)
	{
		if (CollisionMgr::GetInst()->MouseWithBoxCollide(iter->m_Collision) && INPUT->GetButtonDown())
		{
			if (num == 1)
			{
				SceneDirector::GetInst()->ChangeScene(new StageOne());
				break;
			}

			if (num == 2)
			{
				App::GetInst()->Release();
				exit(0);
			}

			if (num == 3)
			{
				SceneDirector::GetInst()->ChangeScene(new HOW_PLAY());
				break;
			}
			if (num == 4)
			{
				SceneDirector::GetInst()->ChangeScene(new END());
				break;
			}
		}

		num++;
	}
	if (INPUT->GetKey(VK_ESCAPE) == KeyState::DOWN)
	{
		App::GetInst()->Release();
		exit(0);
	}
	if (!mm)
	{
		ObjectMgr::GetInst()->Release();
		mm = true;

		ObjectMgr::GetInst()->KeepObject(new Player(), "Player");
	}
}

void SceneMain::Render()
{
	m_BackGround->Render();

	for (auto iter : m_Buttons) {
		iter->Render();
	}
}
