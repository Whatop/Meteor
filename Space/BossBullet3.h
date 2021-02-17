#pragma once
class BossBullet3 : public Object
{
private:
	Sprite* m_Bullet;

	float m_Speed;

public:
	BossBullet3(Vec2 MonsterPos);
	~BossBullet3();

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

