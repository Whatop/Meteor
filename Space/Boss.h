#pragma once
class Boss : public Object
{
private:
	Sprite* m_Boss;

	float BossBulletDelay;

	int Hp;
	int num;
	bool move;
public:
	float Speed;
	Boss();
	~Boss();

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};



