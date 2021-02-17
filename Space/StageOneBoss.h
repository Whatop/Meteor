#pragma once

class StageOneBoss : public Object
{
private:
	Sprite* m_Boss;
	LPDIRECT3DDEVICE9 g_pd3dDevice;
	LPD3DXLINE g_pLine;

	float MonsterBulletDelay;
	float SpawnDelay;
	bool boo;
	float Hp;
	int num;
	bool a, b, move;

public:
	float Speed;
	StageOneBoss(Vec2 Pos);
	~StageOneBoss();

	void Update(float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
	void Draw();
	void InitProgram();
};
