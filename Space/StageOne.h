#pragma once
class StageOne : public Object
{
	Sprite* m_BackGround;
	
public:
	StageOne();
	~StageOne();

	void Update(float time);
	void Render();
	
};


