#pragma once
class MMeteor : public Object
{
private:
	Sprite* m_MMeteor;
	float m_Speed;
	int m_Hp;
public:
	MMeteor(Vec2 Pos, float rotation);
	~MMeteor();

	void Update(float time);
	void Render();
	void Move(float time);

	void OnCollision(Object* obj, std::string tag);
};

