#pragma once
class BoomEffect : public Object
{
private:
	Animation* m_Ani;
	int Delay;
public:
	BoomEffect(Vec2 Pos);
	~BoomEffect();

	void Update(float time);
	void Render();
};

