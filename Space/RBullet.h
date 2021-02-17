#pragma once
class RBullet : public Object
{
private:
	Sprite* m_Bullet;
	float m_Speed;
public:
	RBullet(Vec2 Pos, float r);
	~RBullet();
	
	void Update(float time);
	void Render();
	void Move(float time);

	void OnCollision(Object* obj, std::string tag);
};

