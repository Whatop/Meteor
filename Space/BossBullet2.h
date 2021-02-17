#pragma once
class BossBullet2 : public Object
{
private:
	Sprite* m_Bullet;

	float m_Speed;

public:
	BossBullet2(Vec2 MonsterPos);
	~BossBullet2();

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

