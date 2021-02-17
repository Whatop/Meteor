#pragma once
class MonsterBullet : public Object
{
private:
	Sprite* m_Bullet;

	float m_Speed;

public:
	MonsterBullet(Vec2 MonsterPos);
	~MonsterBullet();

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

