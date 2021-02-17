#pragma once
class SIngletonC : public Singleton<SIngletonC>
{
private:
	Vec2 mPosition;
	Vec2 mRotation;
	Vec2 Scale;
	Matrix CamerMatrix;
public:
	SIngletonC();
	~SIngletonC();

	Vec2 GetPosition(void) { return mPosition; }

	void SetPosition(Vec2 Pos);
	void SetRotate(Vec2 rotate);
	void SetScale(Vec2 scale);
	void Update(float time);

	Matrix* GetMatrix() { return &CamerMatrix; }
};

