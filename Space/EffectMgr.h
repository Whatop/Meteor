#pragma once
class EffectMgr : public Object, public Singleton<EffectMgr>
{
	Animation* Effect;
public:
	EffectMgr(std::wstring filename, int start, int end, int speed, Vec2 Pos);
	~EffectMgr();

	int Start;
	int End;

	void Update(float time);
	void Render();
	void OnCollision(Object* other);
};

