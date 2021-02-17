#pragma once
class Level_Item : public Object
{
private:
	Sprite* m_Level_Item;
public:
	Level_Item(Vec2 Pos);
	~Level_Item();

	void Update(float time);
	void Render();

	void OnCollision(Object* obj, std::string tag);

};

