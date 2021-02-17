#include "stdafx.h"
#include "SceneMain.h"
#include "RankScene.h"

RankScene::RankScene()
{
	m_Sprite = Sprite::Create(L"Painting/Scene/Ranking.png");
	m_Sprite->SetPosition(1920 / 2, 1080 / 2);
}

RankScene::~RankScene()
{
}

void RankScene::Update(float time)
{
	if (INPUT->GetKey(VK_ESCAPE) == KeyState::DOWN)
	{
		SceneDirector::GetInst()->ChangeScene(new SceneMain());
	}
}

void RankScene::Render()
{
	m_Sprite->Render();
	int x = 590, y = 335;

	for (auto& iter : RankMgr::GetInst()->m_Users)
	{
		TCHAR szScore[32] = L"";
		TCHAR szName[32] = L"";

		wsprintf(szScore, L"%d", iter->m_Score);
		wsprintfW(szName, L"%s", iter->m_Name);

		Matrix matFont;
		Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);

		D3DXMatrixTranslation(&matFont, 590, y, 0);
		Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
		Renderer::GetInst()->GetFont()->DrawTextW(Renderer::GetInst()->GetSprite(), szName, 32, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

		D3DXMatrixTranslation(&matFont, 1340, y, 0);
		Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
		Renderer::GetInst()->GetFont()->DrawTextW(Renderer::GetInst()->GetSprite(), szScore, 32, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

		Renderer::GetInst()->GetSprite()->End();

		y += 200;
	}
}
