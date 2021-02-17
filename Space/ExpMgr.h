#pragma once

class ExpMgr : public Singleton<ExpMgr>
{
private:
	int m_Exp;
	int m_Level;
public:
	ExpMgr();
	~ExpMgr();

	int GetExp() { return m_Exp; }
	int GetLevel () { return m_Level; }
	void AddExp(int exp) { m_Exp += exp; }
	void AddLevel(int level) { m_Level += level; }
	void ResetExp();
	void ResetLevel();
};