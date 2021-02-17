#pragma once

class App : public Singleton<App>
{
private:
	int m_Width;//����
	int m_Height;//����
	bool m_WindowMode; //0�̸� â��� x 1�̸� â��� �ϲ�?

	HWND m_Hwnd;

	bool _CreateWindow();
	bool _CreateRenderer();

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

public:
	App();
	~App();

	bool Init(int width, int height, bool windowMode); //���� ���� â���
	void Run();
	void Release();
	HWND GetHwnd() { return m_Hwnd; }
	int Mode;
	float Time, CurrentTime, NewTime, DeltaTime, FrameTime;

};

