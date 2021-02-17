#pragma once
class Monster : public Object
{
private:
	Sprite* m_Monster;
	LPDIRECT3DDEVICE9 g_pd3dDevice;
	LPD3DXLINE g_pLine;

	float MonsterBulletDelay;
	float SpawnDelay;
	bool boo;
	float Hp;
	int num;
	bool a,b,move;

public:
	float Speed;
	Monster(Vec2 Pos);
	~Monster();

	void Update(float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
	void Draw();
	void InitProgram();
};
