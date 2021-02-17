#pragma once

#define SAFE_DELETE(x) if(x) {delete x; x = NULL;}
#define Vec2 D3DXVECTOR2
#define Matrix D3DXMATRIX
#define Nor D3DXVec2Normalize
#define _USE_MATH_DEFINES

#include <stdio.h>//
#include <stdlib.h>	
#include <Windows.h>//
#include <d3d9.h>//
#include <d3dx9.h>//
#include <map>//
#include <list>//
#include <vector>//
#include <string>//
#include <time.h>//
#include <conio.h>//
#include <math.h>//
#include <mmsystem.h>//
#include <iostream>//
#include <cmath>//


#include "Singleton.h"
#include "Renderer.h"
#include "App.h"
#include "Object.h"
#include "ObjectMgr.h"
#include "Sprite.h"
#include "Animation.h"
#include "Input.h"
#include "SceneDirector.h"
#include "CollisionMgr.h"
#include "SoundMgr.h"//
#include "RankMgr.h"//
#include "GameMgr.h"//
#include "EffectMgr.h"//
#include "ExpMgr.h"//
#include "SIngletonC.h"//