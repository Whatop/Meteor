#pragma once
class END : public Object
{
private:
	Sprite* m_Sprite;

	Sprite* m_Scene;
	Sprite* Continue;
	TCHAR m_szName[16];
	bool aaa;
	int m_iIndex;
public:
	END();
	~END();

	void Update(float time);
	void Render();

};



