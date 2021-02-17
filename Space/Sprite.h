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

	bool Init(std::wstring fileName);//파일 이름 맞는지 아닌지 맞나?

public:


	RECT GetRect() { return m_Rect; } //반환->Rect
	void SetRectSize(float x, float y);//사이즈 구하기

	static Sprite* Create(std::wstring fileName);//생성  파일 이름
	void Render();
};