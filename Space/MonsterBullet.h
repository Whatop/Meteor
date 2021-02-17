#pragma once
class MonsterBullet : public Object
{
private:
	Sprite* m_Bullet;

	float m_Speed;

public:
	int m_Type;
	MonsterBullet(Vec2 Pos,int Type);
	~MonsterBullet();

	void Update(float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);

};

