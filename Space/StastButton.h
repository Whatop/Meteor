#pragma once
class StartButton : public Object
{

private:
	Sprite* m_StartButton;
	int Hp;

public:

	StartButton();
	~StartButton();

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};
