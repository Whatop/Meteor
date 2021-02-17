#include"stdafx.h"
#include"Sprite.h"
#include"Texture.h"
#include"ResourceMgr.h"
#include "SIngletonC.h"

Sprite::Sprite()
	: m_pSp(Renderer::GetInst()->GetSprite())
{
	A = 255;
	R = 255;
	G = 255;
	B = 255;
	m_pSp->AddRef();
	SetRect(&m_Rect, 0, 0, 0, 0);
}

Sprite::~Sprite()
{
}

bool Sprite::Init(std::wstring fileName)
{
	m_Texture = ResourceMgr::GetInst()->CreateTextureFromFile(fileName);
	if (m_Texture)
	{
		m_Size = m_Texture->GetSize();
		SetRect(&m_Rect, 0, 0, static_cast<int>(m_Size.x), static_cast<int>(m_Size.y));
		return true;
	}
	else
		return false;
}

void Sprite::SetRectSize(float x, float y)
{
	SetRect(&m_Rect, 0, 0, static_cast<int>(m_Size.x / x), static_cast<int>(m_Size.y / y));
}


Sprite* Sprite::Create(std::wstring fileName)
{
	auto sprite = new (std::nothrow) Sprite();
	if (sprite && sprite->Init(fileName))
	{
		return sprite;
	}
	else
	{
		SAFE_DELETE(sprite);
		return nullptr;
	}
}

void Sprite::Render()
{
	if (m_Parent)
	{
		SetRect(&m_Parent->m_Collision, m_Parent->m_Position.x - m_Size.x / 2, m_Parent->m_Position.y - m_Size.y / 2,
			m_Parent->m_Position.x + m_Size.x / 2, m_Parent->m_Position.y + m_Size.y / 2);

		m_Parent->m_Size = m_Size;
	}
	else
	{
		SetRect(&m_Collision, m_Position.x - m_Size.x / 2, m_Position.y - m_Size.y / 2,
			m_Position.x + m_Size.x / 2, m_Position.y + m_Size.y / 2);

	}

	if (m_Visible == false)
		return;
	Matrix m_World = *(SIngletonC::GetInst()->GetMatrix());
	m_World = m_World * GetMatrix();
	m_pSp->Begin(D3DXSPRITE_ALPHABLEND);
	m_pSp->SetTransform(&m_World);
	m_pSp->Draw(m_Texture->GetTexture(), &m_Rect, &D3DXVECTOR3(m_Size.x / 2, m_Size.y / 2, 0),
		0, D3DCOLOR_ARGB(A, R, G, B));
	m_pSp->End();
}