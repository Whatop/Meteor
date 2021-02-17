#include "stdafx.h"
#include "RankMgr.h"

RankMgr::RankMgr()
{
}

RankMgr::~RankMgr()
{
}

void RankMgr::ResetScore()
{
	m_Score = 0;
}

void RankMgr::KeepUser(User* user)
{
	m_Users.push_back(user);
}

void RankMgr::SetRank()
{
	m_Users.sort(stLISTsort());
}
