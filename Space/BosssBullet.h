#pragma once
class BosssBullet : public Object
{
private:
	Sprite* m_Bullet;

	float m_Speed;

public:
	BosssBullet(Vec2 MonsterPos);
	~BosssBullet();

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

