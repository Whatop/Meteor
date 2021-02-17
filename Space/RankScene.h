#pragma once

class RankScene : public Object
{
private:
	Sprite* m_Sprite;

public:
	RankScene();
	~RankScene();

	void Update(float time);
	void Render();
};

