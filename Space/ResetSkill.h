#pragma once
class ResetSkill : public Object
{
private:
	Sprite* m_Level_Item;
public:
	ResetSkill(Vec2 Pos);
	~ResetSkill();

	void Update(float time);
	void Render();

	void OnCollision(Object* obj, std::string tag);

};

