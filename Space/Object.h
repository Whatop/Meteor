#pragma once //�����Ϸ����� �ش� ��� ������ �ѹ��� ����ǵ��� �Ѵ�. �ش� ��������� ������ include �Ǵ� ���� �����ش�. ���������� include �Ǹ� �׶����� ���� ���ǰ� �߰��Ǿ� ��ø�Ǵ� ��찡 ����� �����̴�. �� �ߺ��� ������ ������ ����Ǵ� ���� ���� ���� #pragma once�� ����Ѵ�
class Object  //Object ��ü�� ��ü�� ���� �⺻���� ���¸� ������ �ִ� ��ü�̴�. �ٽ� ���ؼ� �ƹ��͵� ��ӹ��� �ʴ� ������ ��ü��. �ڹٽ�ũ��Ʈ������ ���� �����ϴ� �⺻���� ������ Object�� ����Ѵ�. 
{
public:
	LPDIRECT3DDEVICE9 m_pDev;  //LPDIRECT3D9��  Device�� ������ ��ü �����̰� LPDIRECT3DDEVICE9�� �������� ���� Device�Դϴ�.
	Object* m_Parent;

	Matrix m_wMat;   
	Vec2 m_Position;
	Vec2 m_Scale;
	Vec2 m_Size;
	float m_Rotation;
	std::string m_Tag;

	bool m_Destroy;
	RECT m_Collision;

	bool m_Visible;

	int m_Layer;

public:

	int A;
	int R;
	int G;
	int B;

	Object();
	 ~Object();


protected:
	Matrix GetMatrix();

public:
	virtual void Update(float time);
	virtual void Render();
	virtual void OnCollision(Object* other, std::string tag);
	virtual void Move(float time);


public:
	void Translate(float x, float y);
	void SetScale(float x, float y);
	void SetPosition(float x, float y);
	void SetPosition(Vec2 pos);
	void Rotate(float r);
	void SetDestroy(bool destroy) { m_Destroy = destroy; }
	void SetParent(Object* parent) { m_Parent = parent; }
public:
	bool GetDestroy() { return m_Destroy; }
};