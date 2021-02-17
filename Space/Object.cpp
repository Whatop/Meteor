#include "stdafx.h"  //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "Object.h"


Object::Object() :
	m_pDev(Renderer::GetInst()->GetDevice())
	, m_Position(0.f, 0.f)
	, m_Rotation(0.f)
	, m_Scale(1.f, 1.f)
	, m_Destroy(0)
	, m_Parent(0)
	, m_Visible(true)
	, m_Layer(0)
	, m_Size(0.f, 0.f) 
	, A(255)
	, R(255)
	, G(255)
	, B(255)
{
 	m_pDev->AddRef();
	D3DXMatrixIdentity(&m_wMat);
}


Object::~Object()
{
}

Matrix Object::GetMatrix()
{
	D3DXMatrixTransformation2D(&m_wMat, 0, 0, &m_Scale, 0, m_Rotation, &m_Position);

	if (m_Parent)
		m_wMat *= m_Parent->GetMatrix();

	return m_wMat;
}

void Object::Update(float time)
{
}

void Object::Render()
{
}

void Object::OnCollision(Object* other, std::string tag)
{
}

void Object::Move(float time)
{
}

void Object::Translate(float x, float y)
{
	m_Position.x += x;
	m_Position.y += y;
}

void Object::SetPosition(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void Object::SetPosition(Vec2 pos)
{
	m_Position = pos;
}

void Object::SetScale(float x, float y)
{
	m_Scale.x = x;
	m_Scale.y = y;
}

void Object::Rotate(float r)
{
	m_Rotation += r;
}
