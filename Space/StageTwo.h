#pragma once
class StageTwo : public Object
{
	Sprite* m_BackGround;

public:
	StageTwo();
	~StageTwo();

	void Update(float time);
	void Render();

};


