#pragma once
class Animation : public Object
{
private:
	std::vector<Sprite*> m_Anim;
	//���Ҽ� �ִ� �迭
	int m_Delay;
	bool m_AutoPlay;
	int m_FrameCount;

public:
	int m_CurrentFrame;//ó��
	int m_LastFrame;//������
public:
	Animation();
	~Animation();

	void SetFrame(int frame) { m_CurrentFrame = frame; } // ����
	void AddFrame(std::wstring fileName); //�����̸� ����?
	void AddContinueFrame(std::wstring fileName, int firstFrame, int lastFrame);// ���� �̸� ó�� ������

	void Init(int delay, bool play);// ������ ����
	void Update(float time);
	void Render();
};

