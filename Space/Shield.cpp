#include "stdafx.h"
#include "Shield.h"
#include "Boom.h"

Shield::Shield(Vec2 Pos) : Delay(0)
{
	m_Shield = Sprite::Create(L"Painting/Shield.png");
	m_Shield->SetParent(this);
	SetPosition(Pos);

}

Shield::~Shield()
{
}

void Shield::Update(float time)
{  
	

	if (INPUT->GetKey(VK_UP) == KeyState::PRESS && m_Position.y >= 0)
	{
		m_Position.y -= 10;
	}
	if (INPUT->GetKey(VK_DOWN) == KeyState::PRESS && m_Position.y <= 1080)
	{
		m_Position.y += 10;
	}
	if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS && m_Position.x <= 5200)
	{
		m_Position.x += 10;
	}
	if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS && m_Position.x >= 0)
	{
		m_Position.x -= 10;
	}

	if (Delay >= 150)
	{
		Delay = 0;
	}
	Delay++;

	if (Delay >= 150)
	{
		Ogr->RemoveObject(this);
	}
}

void Shield::Render()
{
	m_Shield->Render();
}

