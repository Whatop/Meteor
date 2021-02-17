#pragma once

enum class Stage
{
	STAGEONE,
	STAGETWO,
	BOSS,
	NONE
};


#define SCENE SceneDirector::GetInst()

class SceneDirector : public Singleton<SceneDirector>, public Object
{
private:
	Object* m_CurrentScene;
public:
	Stage m_Stage;

	SceneDirector();

	void ChangeScene(Object* newscene);
	void Update(float time);
	void Render();

	Vec2 GetSize() { return m_CurrentScene->m_Size; }
	Vec2 GetPos() { return m_CurrentScene->m_Position; }
};
