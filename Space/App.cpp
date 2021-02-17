#include "stdafx.h"
#include "App.h"


App::App() :
	CurrentTime(0)
	, DeltaTime(0)
	, FrameTime(0)
	, NewTime(0)
	, Time(0)
	, m_Height(0)
	, m_Hwnd(0)
	, m_Width(0)
	, m_WindowMode(true)
{
}


App::~App()
{
}

bool App::Init(int width, int height, bool windowMode)
{
	m_Width = width;
	m_Height = height;
	m_WindowMode = windowMode;

	if (!_CreateWindow())
		return false;

	if (!_CreateRenderer())
		return false;

	Time = 0.0f;
	CurrentTime = GetTickCount64(); //1ms 단위로 카운팅된다  // 49.7일 동안 윈도우즈를 종료하지 않을 경우 0으로 초기화되는 것이다.
	return true;
}

void App::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	srand(time(NULL)); // rand 초기화 time 항상변함

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			NewTime = GetTickCount64(); //1ms 단위로 카운팅된다
			FrameTime = NewTime - CurrentTime;
			CurrentTime = NewTime;

			DeltaTime = FrameTime / 1000.0f;
			Renderer::GetInst()->Begin();
			SceneDirector::GetInst()->Update(Time);
			Time += DeltaTime;
			SceneDirector::GetInst()->Render();
			Renderer::GetInst()->End();
		}
	}

}

void App::Release()
{
	FreeConsole();
	Renderer::GetInst()->Release();
}

LRESULT App::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
		INPUT->ButtonDown(true);
		break;

	case WM_LBUTTONUP:
		INPUT->ButtonDown(false);
		break;

	case WM_RBUTTONDOWN:
		INPUT->RButtonDown(true);
		break;

	case WM_RBUTTONUP:
		INPUT->RButtonDown(false);
		break;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

bool App::_CreateWindow()
{
	WNDCLASS wc = {};
	wc.lpszClassName = L"SoundPlay";
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.lpfnWndProc = WndProc;

	RegisterClass(&wc);

	DWORD Style = 0;

	if (m_WindowMode)
		Style = WS_OVERLAPPEDWINDOW;
	else
		Style = WS_POPUP | WS_EX_TOPMOST;

	HWND hWnd = CreateWindow(wc.lpszClassName, wc.lpszClassName, Style, 0, 0, m_Width, m_Height, 0, 0, 0, 0);
	if (hWnd)
		m_Hwnd = hWnd;
	else
		return false;

	ShowWindow(m_Hwnd, SW_SHOWDEFAULT);


	return true;
}

bool App::_CreateRenderer()
{
	if (!(Renderer::GetInst()->Init(m_Width, m_Height, m_WindowMode)))
		return false;

	return true;
}
