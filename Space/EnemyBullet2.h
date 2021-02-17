#pragma once
class EnemyBullet2 : public Object
{
private:
	Sprite* m_Bullet;

	float m_Speed;

public:
	EnemyBullet2(Vec2 MosterPos);
	~EnemyBullet2();

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

