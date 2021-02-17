#pragma once

#define GM GameMgr::GetInst()

class GameMgr : public Singleton<GameMgr>, public Object
{
public:
	std::list<Animation*> m_Effects;
	std::list<Animation*> m_Hill;

	bool GameClear;
	bool Check;
	float StartTime;
	Vec2 ptLine1[58];

public:
	GameMgr();

	void CreateEnemy(Stage stage);
	void Update(float time);

	void ReSet();
};

