#pragma once
class Enemy : public Object
{
private:
	Sprite* m_Enemy;

	float EnemyBulletDelay;

	int HP;
	int num;
	bool move;
	//Animation* m_PlayerAni;
public:
	float Speed;

	Enemy();
	~Enemy();

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);

};

