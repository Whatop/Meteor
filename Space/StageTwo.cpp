#include "stdafx.h"
#include "StageTwo.h"
#include "Monster.h"
#include "Player.h"
StageTwo::StageTwo()
{

	if (SceneDirector::GetInst()->m_Stage == Stage::STAGEONE)
	{
		ObjectMgr::GetInst()->Release();
	}
	GameMgr::GetInst()->CreateEnemy(Stage::STAGETWO);

	SceneDirector::GetInst()->m_Stage = Stage::STAGETWO;

	ObjectMgr::GetInst()->KeepObject(new Player(), "Player");

	m_BackGround = Sprite::Create(L"Painting/StageTwo.png");
	m_BackGround->SetParent(this);
	SetPosition(6500, 590);
}

StageTwo::~StageTwo()
{
}

void StageTwo::Update(float time)
{
	if (INPUT->GetKey(VK_ESCAPE) == KeyState::DOWN)
	{
		App::GetInst()->Release();
		exit(0);
	}
	GameMgr::GetInst()->Update(time);

}

void StageTwo::Render()
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