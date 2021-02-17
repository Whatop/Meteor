#include "stdafx.h"
#include "BoomEffect.h"

BoomEffect::BoomEffect(Vec2 Pos)
{
	m_Ani = new Animation();
	m_Ani->Init(10, true);
	m_Ani->AddContinueFrame(L"Painting/Boom/", 1, 6);
	m_Ani->SetParent(this);

	SetPosition(Pos.x, Pos.y);
}


BoomEffect::~BoomEffect()
{
}

void BoomEffect::Update(float time)
{
	if (Delay >= 150)
	{
		Delay = 0;
	}
	Delay++;

	if (Delay >= 150)
	{
		Ogr->RemoveObject(this);
	}


	m_Ani->Update(time);
}


void BoomEffect::Render()
{
	m_Ani->Render();
}
