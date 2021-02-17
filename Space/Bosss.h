#pragma once
class Bosss : public Object
{
private:
	Sprite* m_Bosss;

	float BossBulletDelay;
	int Hp;
	int num;
	bool move;
public:
	float Speed;
	Bosss();
	~Bosss();

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

