#pragma once
class Player : public Object,public Singleton<Player>
{
	//체력 무기 아이템 이펙트 
private:
	Sprite* m_Player;
	Sprite* m_Weapon;
	Sprite* m_Item;
	Sprite* m_PlayerState;
	Sprite* m_Hpsp;
	Sprite* m_spBoom;
	Sprite* m_spShield;
	
	EffectMgr* m_Effect;
	LPDIRECT3DDEVICE9 g_pd3dDevice;
	LPD3DXLINE g_pLine;

	float GunDelay;
	float GDelay;
	float RDelay;
	float SDelay;
	float ADelay;
	bool WeaponsKey1;
	bool WeaponsKey2;
	
	int m_Level;
	int MaxExp;

	bool m_Skill;
	int m_Exp;
	bool KeyBoardDelay;
	int HP;
	int MaxHP;
	int Su;
	bool mm;
	bool boo;

	bool m_Bgm;
	bool invincibility;

	bool m_Shield;
	bool m_Boom;
	bool CameraBoss;
	bool m_Boom1;
	bool m_Boom2;
public:
	float Speed;
	int num;
	bool Cool_Time1;
	bool Cool_Time2;
	bool m_Skill_Type;
	bool m_Skill1;
	bool m_Skill2;
	bool m_Atk;
	bool AtkCheck;
	bool AlphaCheck;
	Player();
	~Player();

	void Update(float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);

	void Level(float time);
	void Move(float time);
	void Shot(float time);

	void Draw();
	void InitProgram();
};

