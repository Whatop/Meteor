#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "END.h"
#include "DeathStage.h"
#include "Monster.h"
#include "GameMgr.h"
GameMgr::GameMgr() : GameClear(false)
, Check(false)
, StartTime(0.f)
{
}

void GameMgr::CreateEnemy(Stage stage)
{	
	if (stage == Stage::STAGEONE)
	{
		Vec2 A;
		A.x = 4050;
		A.y = 540;
		Ogr->KeepObject(new Monster(A), "Monster");
	}
//	if (stage == Stage::STAGEONE)
	//{
		//for (int i = 0; i <= 10; i++)
		/*{
			int random = rand() % 3 + 1;
			Vec2 ePos;
			ePos.x = rand() % 3400 + 100;
			ePos.y = rand() % 3400 + 100;
			printf("%f %f \n", ePos.x, ePos.y);
			if (random == 1)
				Ogr->KeepObject(new Enemy(ePos, ENEMYTYPE::NOMAL),"Monster");
			else
				Ogr->KeepObject(new Enemy(ePos, ENEMYTYPE::NOMAL2),"Monster");*/
		//
		//}
		//Vec2 A;
		//A.x = 1300;
		//A.y = 400;
		//Ogr->KeepObject(new Enemy(A), "Monster");
	//}
	/*else if (stage == Stage::STAGETWO)
	{

	}
	else if (stage == Stage::STAGETHREE)
	{
		for (int i = 0; i <= 10; i++)
		{
			int random = rand() % 2 + 1;
			Vec2 ePos;
			ePos.x = rand() % 3400 + 100;
			ePos.y = rand() % 3400 + 100;
			printf("%f %f \n", ePos.x, ePos.y);
			if (random == 1)
				Ogr->KeepObject(new Enemy(ePos, ENEMYTYPE::NOMAL), "Monster");
			else
				Ogr->KeepObject(new Enemy(ePos, ENEMYTYPE::NOMAL2), "Monster");

		}

		Vec2 A;
		A.x = 1750;
		A.y = 1750;
		Ogr->KeepObject(new Boss(A), "Monster");

	}*/

}


void GameMgr::Update(float time)
{
	if (GameClear)
	{
		if (Check == false)
		{
			StartTime = time;
			Check = true;
		}

		if (time - StartTime >= 2)
			SCENE->ChangeScene(new END());
	}

}


void GameMgr::ReSet()
{
	GameClear = false;
	Check = false;
	StartTime = 0.f;

}

