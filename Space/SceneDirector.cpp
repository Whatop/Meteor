#include "stdafx.h" //���� ������� �ʴ� �� �ҽ��� stdafx�� �ְ� �̸� �������� �صд�.������ stdafx.h�� ����Ͽ� ��ü ������ �ӵ��� ��½�Ų��.
#include "SceneDirector.h"    //SceneDirector ����!


SceneDirector::SceneDirector() 
{
}

void SceneDirector::ChangeScene(Object* newScene)
{
	if (m_CurrentScene)
		m_CurrentScene = NULL;

	m_CurrentScene = newScene;
}

void SceneDirector::Update(float time)
{
	Input::GetInst()->Update();

	if (m_CurrentScene)
		m_CurrentScene->Update(time);
	Ogr->Update(time); //deltaTime �� �������� �Ϸ�Ǳ���� �ɸ� �ð��� ���մϴ�. ��ǻ���� ������ �������� ���� Ŀ����.

}

void SceneDirector::Render()
{
	if (m_CurrentScene)
		m_CurrentScene->Render();

	Ogr->Render();
}
