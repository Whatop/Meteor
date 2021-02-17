#include "stdafx.h"
#include "DeathStage.h"
#include "SceneMain.h"
#include "SIngletonC.h"
DeathStage::DeathStage() : mm(false)
{
	SoundMgr::GetInst()->Stop();

	m_DeathScene = Sprite::Create(L"Painting/BackGround/You_Die.png");
	m_DeathScene->SetPosition(1920 / 2, 1080 / 2);

	m_ExitButton = Sprite::Create(L"Painting/2/Scene/ExitButton1.png");
	m_ExitButton->SetPosition(1700, 700);

	m_Backbutton = Sprite::Create(L"Painting/2/Scene/Backbutton.png");
	m_Backbutton->SetPosition(1700, 900);
	SceneDirector::GetInst()->m_Stage = Stage::NONE;
	SoundMgr::GetInst()->Play(L"GameOver.wav", true);

}


DeathStage::~DeathStage()
{
}

void DeathStage::Update(float time)
{
	SIngletonC::GetInst()->SetPosition(Vec2(0.f, 0.f));

	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_ExitButton->m_Collision) && INPUT->GetButtonDown())
	{
		exit(0);
	}
	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_Backbutton->m_Collision) && INPUT->GetButtonDown())
	{

		SceneDirector::GetInst()->ChangeScene(new SceneMain());
	}
	else if (INPUT->GetKey(VK_SPACE) == KeyState::PRESS)
	{
		SceneDirector::GetInst()->ChangeScene(new SceneMain());

	}
	if (!mm)
	{
		ObjectMgr::GetInst()->Release();
		mm = true;
	}
}

void DeathStage::Render()
{
	m_DeathScene->Render();
	m_ExitButton->Render();
	m_Backbutton->Render();
}
