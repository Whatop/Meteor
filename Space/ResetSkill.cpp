#include "stdafx.h"
#include "ResetSkill.h"

ResetSkill::ResetSkill(Vec2 Pos)
{
	m_Level_Item = Sprite::Create(L"Painting/02_ITEM/item_warter_bottle_01.png");
	m_Level_Item->SetParent(this);
	SetPosition(Pos);
}

ResetSkill::~ResetSkill()
{
}

void ResetSkill::Update(float time)
{
	Ogr->CollideCheak(this, "Player");

}

void ResetSkill::Render()
{
	m_Level_Item->Render();
}

void ResetSkill::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Player")
	{
		Ogr->RemoveObject(this);
	}
}
