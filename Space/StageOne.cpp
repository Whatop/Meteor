#include "stdafx.h"
#include "StageOne.h"
#include "Monster.h"
#include "Player.h"
StageOne::StageOne()
{
	SoundMgr::GetInst()->Stop();

	if (SceneDirector::GetInst()->m_Stage == Stage::STAGETWO)
	{
		ObjectMgr::GetInst()->Release();
	}

	m_BackGround = Sprite::Create(L"Painting/BG_GreenHills.png");
	m_BackGround->SetParent(this);
	SetPosition(3700, 540);


	GameMgr::GetInst()->CreateEnemy(Stage::STAGEONE);
	GameMgr::GetInst()->ReSet();

	SceneDirector::GetInst()->m_Stage = Stage::STAGEONE;

	//SoundMgr::GetInst()->Play(L"StageOne.wav", true);

	//ObjectMgr::GetInst()->KeepObject(new Player(), "Player");
}
	
StageOne::~StageOne()
{
}

void StageOne::Update(float time)
{
	if (INPUT->GetKey(VK_ESCAPE) == KeyState::DOWN)
	{
		App::GetInst()->Release();
		exit(0);
	}
	GameMgr::GetInst()->Update(time);
}

void StageOne::Render()
{
	m_BackGround->Render();
	//3 GameMgr::GetInst()->Render();

	TCHAR szScore[32] = L"";
	int Score = RankMgr::GetInst()->GetScore();
	wsprintf(szScore, L"Score : %d", Score);

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	Matrix matFont;

	D3DXMatrixTranslation(&matFont, 500, 30, 0);
	Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
	Renderer::GetInst()->GetBulletFont()->DrawTextW(Renderer::GetInst()->GetSprite(),
		szScore, 32, NULL, NULL, D3DCOLOR_ARGB(255, 0, 0, 255));
	Renderer::GetInst()->GetSprite()->End();
}