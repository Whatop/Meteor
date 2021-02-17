#pragma once
class Texture;
class Sprite : public Object
{
private:
	LPD3DXSPRITE m_pSp;
	Texture* m_Texture;
	RECT m_Rect;

	Sprite();
	~Sprite();

	bool Init(std::wstring fileName);//���� �̸� �´��� �ƴ��� �³�?

public:


	RECT GetRect() { return m_Rect; } //��ȯ->Rect
	void SetRectSize(float x, float y);//������ ���ϱ�

	static Sprite* Create(std::wstring fileName);//����  ���� �̸�
	void Render();
};