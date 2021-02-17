#include "stdafx.h"
#include "EffectMgr.h"

EffectMgr::EffectMgr(std::wstring filename, int start, int speed, int end, Vec2 Pos)
{
	Effect = new Animation();
	Effect->AddContinueFrame(filename, start, end);
	Effect->Init(speed, true);
	Effect->SetParent(this);
	Effect->m_Position = Pos;


	Start = start;
	End = end;

	m_Layer = 2;
}

EffectMgr::~EffectMgr()
{
}

void EffectMgr::Update(float time)
{
	if (Effect->m_CurrentFrame >= End - 1)
	{
		Ogr->RemoveObject(this);
	}
	Effect->Update(time);
}

void EffectMgr::Render()
{
	Effect->Render();
}

void EffectMgr::OnCollision(Object* other)
{
}
