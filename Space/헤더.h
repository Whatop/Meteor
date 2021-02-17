#pragma once

class MonsterBullet2 : public Object
{
private:
	Sprite* m_Bullet;

	float m_Speed;

	public
		MonsterBullet2(Vec2 MonsterPos);
	~MonsterBullet2();

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

