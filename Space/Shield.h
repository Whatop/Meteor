#pragma once
class Shield : public Object
{
private:
	Sprite* m_Shield;
	int Delay;
	bool boo;
public:
	Shield(Vec2 Pos);
	~Shield();

	void Update(float time);
	void Render();
};

