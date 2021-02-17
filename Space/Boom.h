#pragma once
class Boom : public Object
{
private:
	Sprite* m_Boom;
	int speed;
	int Speed;
	int m_Type;
public:
	Boom(Vec2 Pos,int type);
	~Boom();

	void Update(float time);
	void Render();

	void OnCollision(Object* obj, std::string tag);

};

