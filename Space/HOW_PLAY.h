#pragma once
class HOW_PLAY : public Object
{

	Sprite* m_HOWScene;
	Sprite* m_Backbutton;
public:
	HOW_PLAY();
	~HOW_PLAY();

	void Update( float time);
	void Render();

};



