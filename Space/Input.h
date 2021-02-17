#pragma once
enum class KeyState
{
	DOWN,// 눌렀
	UP,// 눌렀다 땔
	PRESS,//누르고 있기
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

	void KeyBoardUpdate();//키보드 
	void MouseUpdate();//마우스 
public:
	Input();
	~Input();

	void Update();
	void ButtonDown(bool down); // 눌려져 있나? X O
	void RButtonDown(bool down); // 눌려져 있나? X O
	KeyState GetKey(int key); //상태 
	Vec2 GetMousePos() { return m_MousePosition; }  //반환 -> 마우스 업데이트
	bool GetButtonDown() { return m_ButtonDown; }   //반환 -> 버튼으로 
	bool GetRButtonDown() { return m_RButtonDown; } //반환->  R버튼으로 

};

