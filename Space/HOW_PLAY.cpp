#include "stdafx.h"
#include "HOW_PLAY.h"
#include "SIngletonC.h"
#include "SceneMain.h"
HOW_PLAY::HOW_PLAY()
{
	m_HOWScene = Sprite::Create(L"Painting/2/Scene/HowToplay.png");
	m_HOWScene->SetPosition(1920 / 2, 1080 / 2);
	m_Backbutton = Sprite::Create(L"Painting/2/Scene/Backbutton.png");
	m_Backbutton->SetPosition(1700, 900);
	SceneDirector::GetInst()->m_Stage = Stage::NONE;

}

HOW_PLAY::~HOW_PLAY()
{
}

void HOW_PLAY::Update(float time)
{
	SIngletonC::GetInst()->SetPosition(Vec2(0.f, 0.f));

	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_Backbutton->m_Collision) && INPUT->GetButtonDown())
	{

		SceneDirector::GetInst()->ChangeScene(new SceneMain());
	}
}

void HOW_PLAY::Render()
{
	m_HOWScene->Render();
	m_Backbutton->Render();
}
