#include "stdafx.h"  //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "SoundMgr.h"


SoundMgr::SoundMgr()
{
}


SoundMgr::~SoundMgr()
{
}

void SoundMgr::Play(const WCHAR* pFileName, bool loop)
{
	WCHAR szFullPath[256] = L"../Sound/";
	lstrcatW(szFullPath, pFileName);

	if (!loop)
	{
		PlaySound(szFullPath, NULL, SND_ASYNC | SND_NOSTOP | SND_NODEFAULT | SND_FILENAME);
	}
	else if (loop)
	{
		PlaySound(szFullPath, NULL, SND_ASYNC | SND_LOOP | SND_NOSTOP | SND_NODEFAULT | SND_FILENAME);
	}
}

void SoundMgr::Stop()
{
	PlaySound(nullptr, NULL, SND_ASYNC);
}