#pragma once
class Hill : public Object
{
private:
	Sprite* m_Hill;
public:
	Hill(Vec2 Pos);
	~Hill();

	void Update(float time);
	void Render();

	void OnCollision(Object* obj, std::string tag);

};

