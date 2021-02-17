#pragma once

class Boss3Bullet : public Object
{
private:
	Sprite* m_Bullet;

	float m_Speed;

public:
	Boss3Bullet(Vec2 MonsterPos);
	~Boss3Bullet();

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

