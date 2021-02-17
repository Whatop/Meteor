#include "stdafx.h"
#include "Level_Item.h"

Level_Item::Level_Item(Vec2 Pos)
{
	m_Level_Item = Sprite::Create(L"Painting/GameElements/Star.png");
	m_Level_Item->SetParent(this);
	SetPosition(Pos);
}

Level_Item::~Level_Item()
{
}

void Level_Item::Update(float time)
{
	Ogr->CollideCheak(this, "Player");

}

void Level_Item::Render()
{
	m_Level_Item->Render();
}

void Level_Item::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Player")
	{
		Ogr->RemoveObject(this);
	}
}
