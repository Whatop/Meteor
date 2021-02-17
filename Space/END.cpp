#include "stdafx.h"
#include "END.h"
#include "SceneMain.h"
#include "SIngletonC.h"
END::END()
{
	m_Sprite = Sprite::Create(L"Painting/Scene/ClearScene.png");
	m_Sprite->SetPosition(1920 / 2, 1080 / 2);

	aaa = false;
	ZeroMemory(m_szName, sizeof(TCHAR) * 16);
	m_iIndex = 0;
	SceneDirector::GetInst()->m_Stage = Stage::NONE;


}


END::~END()
{
}

void END::Update(float time)
{
	SIngletonC::GetInst()->SetPosition(Vec2(0.f, 0.f));

	if (aaa == false)
	{
		Ogr->Release();
		aaa = true;
	}
}

void END::Render()
{
	m_Sprite->Render();

	TCHAR szScore[32] = L"";
	int Score = RankMgr::GetInst()->GetScore();

	if (m_iIndex <= 7)
	{
		if (INPUT->GetKey('A') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'A';
			++m_iIndex;
		}

		if (INPUT->GetKey('B') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'B';
			++m_iIndex;
		}

		if (INPUT->GetKey('C') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'C';
			++m_iIndex;
		}

		if (INPUT->GetKey('C') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'C';
			++m_iIndex;
		}

		if (INPUT->GetKey('D') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'D';
			++m_iIndex;
		}

		if (INPUT->GetKey('E') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'E';
			++m_iIndex;
		}

		if (INPUT->GetKey('F') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'F';
			++m_iIndex;
		}

		if (INPUT->GetKey('G') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'G';
			++m_iIndex;
		}

		if (INPUT->GetKey('H') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'H';
			++m_iIndex;
		}

		if (INPUT->GetKey('I') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'I';
			++m_iIndex;
		}

		if (INPUT->GetKey('J') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'J';
			++m_iIndex;
		}

		if (INPUT->GetKey('K') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'K';
			++m_iIndex;
		}

		if (INPUT->GetKey('L') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'L';
			++m_iIndex;
		}

		if (INPUT->GetKey('M') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'M';
			++m_iIndex;
		}

		if (INPUT->GetKey('N') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'N';
			++m_iIndex;
		}

		if (INPUT->GetKey('O') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'O';
			++m_iIndex;
		}

		if (INPUT->GetKey('P') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'P';
			++m_iIndex;
		}

		if (INPUT->GetKey('Q') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'Q';
			++m_iIndex;
		}

		if (INPUT->GetKey('R') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'R';
			++m_iIndex;
		}

		if (INPUT->GetKey('S') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'S';
			++m_iIndex;
		}

		if (INPUT->GetKey('T') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'T';
			++m_iIndex;
		}

		if (INPUT->GetKey('U') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'U';
			++m_iIndex;
		}

		if (INPUT->GetKey('V') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'V';
			++m_iIndex;
		}

		if (INPUT->GetKey('W') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'W';
			++m_iIndex;
		}

		if (INPUT->GetKey('X') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'X';
			++m_iIndex;
		}

		if (INPUT->GetKey('Y') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'Y';
			++m_iIndex;
		}

		if (INPUT->GetKey('Z') == KeyState::DOWN)
		{
			m_szName[m_iIndex] = 'Z';
			++m_iIndex;
		}
	}

	if (INPUT->GetKey(VK_BACK) == KeyState::DOWN && m_iIndex > 0)
	{
		--m_iIndex;
		m_szName[m_iIndex] = NULL;
	}

	wsprintf(szScore, L"%d", Score);

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	Matrix matFont;

	D3DXMatrixTranslation(&matFont, 548, 500, 0);
	Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
	Renderer::GetInst()->GetFont()->DrawTextW(Renderer::GetInst()->GetSprite(), szScore, 32, NULL, NULL, D3DCOLOR_ARGB(255, 0, 0, 0));

	D3DXMatrixTranslation(&matFont, 548, 680, 0);
	Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
	Renderer::GetInst()->GetFont()->DrawTextW(Renderer::GetInst()->GetSprite(), m_szName, 16, NULL, NULL, D3DCOLOR_ARGB(255, 0, 0, 0));
	Renderer::GetInst()->GetSprite()->End();

	if (INPUT->GetKey(VK_RETURN) == KeyState::DOWN)
	{
		User* user = new User;
		wcscpy_s(user->m_Name, m_szName);
		user->m_Score = Score;

		RankMgr::GetInst()->KeepUser(user);
		RankMgr::GetInst()->ResetScore();
		RankMgr::GetInst()->SetRank();
		if (RankMgr::GetInst()->m_Users.size() > 3)
			RankMgr::GetInst()->m_Users.pop_back();

		SceneDirector::GetInst()->ChangeScene(new SceneMain	());
	}


}
