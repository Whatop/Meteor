#pragma once
class Meteor : public Object
{
private:
	Sprite* m_BMeteor;
	float m_Speed;
	int m_Hp;
public:
	Meteor(Vec2 Pos, float rotation);
	~Meteor();

	void Update(float time);
	void Render();
	void Move(float time);

	void OnCollision(Object* obj, std::string tag);
};

