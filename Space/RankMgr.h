#pragma once

class User
{
public:
	int m_Score;
	TCHAR m_Name[16];
};

class RankMgr : public Singleton<RankMgr>
{
private:
	int m_Score;
public:
	RankMgr();
	~RankMgr();

	std::list<User*>m_Users;
	struct stLISTsort
	{
		bool operator()(const User* pObject1, const User* pObject2)const
		{
			if (pObject1->m_Score > pObject2->m_Score)
			{
				return TRUE;
			}
			return FALSE;
		}
	};

	int GetScore() { return m_Score; }
	void AddScore(int score) { m_Score += score; }
	void ResetScore();
	void KeepUser(User* user);
	void SetRank();
};