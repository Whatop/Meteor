#include "stdafx.h"
#include "Hill.h"

Hill::Hill(Vec2 Pos)
{
	m_Hill = Sprite::Create(L"Painting/02_ITEM/item_emergency_kit_01.png");
	m_Hill->SetParent(this);
	SetPosition(Pos);
}

Hill::~Hill()
{
}

void Hill::Update(float time)
{
	Ogr->CollideCheak(this, "Player");

}

void Hill::Render()
{
	m_Hill->Render();
}

void Hill::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Player")
	{
		Ogr->RemoveObject(this);
	}
}
