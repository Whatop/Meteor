#pragma once
class Boss3 : public Object
{
private:
	Sprite* m_Boss3;

	float BossBulletDelay;
	int Hp;
	int num;
	bool move;
public:
	float Speed;
	Boss3();
	~Boss3();

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

