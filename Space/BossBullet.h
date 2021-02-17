#pragma once
class BossBullet : public Object
{
private:
	Sprite* m_Bullet;

	float m_Speed;

public:
	BossBullet(Vec2 MonsterPos);
	~BossBullet();

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

