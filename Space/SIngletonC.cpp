#include "stdafx.h"
#include "SIngletonC.h"

SIngletonC::SIngletonC()
{
}

SIngletonC::~SIngletonC()
{
}

void SIngletonC::SetPosition(Vec2 Pos)
{
	mPosition = -Pos;
}

void SIngletonC::SetRotate(Vec2 rotate)
{
	mRotation = rotate;
}

void SIngletonC::SetScale(Vec2 scale)
{
	Scale = scale;
}

void SIngletonC::Update(float time)
{
	Matrix m_Trans;
	D3DXMatrixTranslation(&m_Trans, mPosition.x, mPosition.y, 0);

	Matrix m_Scale;
	D3DXMatrixScaling(&m_Scale, Scale.x, Scale.y, 1);

	static float test = 0.f;
	test += 0.00000001;
	Matrix m_RotateY;
	D3DXMatrixRotationZ(&m_RotateY, test * 2.f);
	CamerMatrix = m_Scale * m_RotateY * m_Trans;

}
