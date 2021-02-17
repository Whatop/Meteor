#pragma once

class App : public Singleton<App>
{
private:
	int m_Width;//가로
	int m_Height;//세로
	bool m_WindowMode; //0이면 창모드 x 1이면 창모드 일껄?

	HWND m_Hwnd;

	bool _CreateWindow();
	bool _CreateRenderer();

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

public:
	App();
	~App();

	bool Init(int width, int height, bool windowMode); //가로 세로 창모드
	void Run();
	void Release();
	HWND GetHwnd() { return m_Hwnd; }
	int Mode;
	float Time, CurrentTime, NewTime, DeltaTime, FrameTime;

};

