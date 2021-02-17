#pragma once
class EnemyBullet : public Object
{
private:
	Sprite* m_Bullet;

	float m_Speed;

public:
	EnemyBullet(Vec2 MosterPos);
	~EnemyBullet();

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

