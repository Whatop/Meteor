#pragma once
class SceneMain : public Object
{
private:
	std::list<Object*> m_Buttons;

	Sprite* m_BackGround;
	Sprite* m_Start;
	Sprite* m_Help;
	Sprite* m_Exit;
	Sprite* m_Rank;
	bool mm;
public:
	SceneMain();
	~SceneMain();

	void Update(float time);
	void Render();

};

