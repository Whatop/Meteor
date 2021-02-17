#pragma once
class DeathStage : public Object
{

private:
	Sprite* m_DeathScene;
	Sprite* m_ExitButton;
	Sprite* m_Backbutton;
	bool mm;

	public:
		DeathStage();
		~DeathStage();

		void Update(float time);
		void Render();
};

