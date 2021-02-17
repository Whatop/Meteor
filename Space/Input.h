#pragma once
enum class KeyState
{
	DOWN,// ����
	UP,// ������ ��
	PRESS,//������ �ֱ�
	NONE //X
};

#define INPUT Input::GetInst()

class Input : public Singleton<Input>
{
private:
	int m_CurrentState[256];
	int m_PrevState[256];

	bool m_bCurrentState;
	bool m_bPrevState;

	Vec2 m_MousePosition;
	bool m_ButtonDown;
	bool m_RButtonDown;

	void KeyBoardUpdate();//Ű���� 
	void MouseUpdate();//���콺 
public:
	Input();
	~Input();

	void Update();
	void ButtonDown(bool down); // ������ �ֳ�? X O
	void RButtonDown(bool down); // ������ �ֳ�? X O
	KeyState GetKey(int key); //���� 
	Vec2 GetMousePos() { return m_MousePosition; }  //��ȯ -> ���콺 ������Ʈ
	bool GetButtonDown() { return m_ButtonDown; }   //��ȯ -> ��ư���� 
	bool GetRButtonDown() { return m_RButtonDown; } //��ȯ->  R��ư���� 

};

