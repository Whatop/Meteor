#pragma once
class SMeteor : public Object
{
private:
	Sprite* m_SMeteor;
	float m_Speed;
	int m_Hp;
	Vec2 m_Dir;
public:
	SMeteor(Vec2 Pos, float rotation);
	~SMeteor();

	void Update(float time);
	void Move(float time);
	void Render();

	void OnCollision(Object* obj, std::string tag);
};

