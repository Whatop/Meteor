#pragma once
class Animation : public Object
{
private:
	std::vector<Sprite*> m_Anim;
	//변할수 있는 배열
	int m_Delay;
	bool m_AutoPlay;
	int m_FrameCount;

public:
	int m_CurrentFrame;//처음
	int m_LastFrame;//마지막
public:
	Animation();
	~Animation();

	void SetFrame(int frame) { m_CurrentFrame = frame; } // 생성
	void AddFrame(std::wstring fileName); //파일이름 복사?
	void AddContinueFrame(std::wstring fileName, int firstFrame, int lastFrame);// 파일 이름 처음 마지막

	void Init(int delay, bool play);// 딜레이 실행
	void Update(float time);
	void Render();
};

