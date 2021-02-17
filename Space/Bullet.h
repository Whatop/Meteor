#pragma once
class Bullet : public Object
{
private:
	Sprite* m_Bullet;
	LPDIRECT3DDEVICE9 g_pd3dDevice;
	LPD3DXLINE g_pLine;
	float m_Speed;
	float GunDelay;
public:
	int m_Type;
	Bullet(Vec2 Pos,int type);
	~Bullet();


	void Update(float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);

};

