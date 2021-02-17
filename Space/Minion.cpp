#include "stdafx.h"
#include "Minion.h"
#include "MonsterBullet.h"
#include "Player.h"
#include "Level_Item.h"
#include "Hill.h"
#include "ResetSkill.h"

Minion::Minion(Vec2 Pos,int type) : move(false), boo(false), num(0), delay(1)
{

    Speed = 10;
    Hp = 20;
    m_Minion = Sprite::Create(L"Painting/Monster.png");
    m_Minion->SetParent(this);
    SetPosition(Pos);
    m_Type = type;
}

Minion::~Minion()
{
}

void Minion::Update(float time)
{
    Ogr->CollideCheak(this, "Bullet");
    Ogr->CollideCheak(this, "Bullet2");
    Ogr->CollideCheak(this, "Bullet3");
    Ogr->CollideCheak(this, "Bullet4");
    Ogr->CollideCheak(this, "Bullet5");

    Ogr->CollideCheak(this, "SBullet");
    Ogr->CollideCheak(this, "SBullet2");
    Ogr->CollideCheak(this, "SBullet3");
    Ogr->CollideCheak(this, "SBullet4");
    Ogr->CollideCheak(this, "SBullet5");
    Ogr->CollideCheak(this, "Boom");
    static float StartTime = time;
    
    switch (m_Type)
    {
    case 1:
        m_Position.x -= 5.f;
        if (m_Position.x <= 0)
        {
            ObjectMgr::GetInst()->RemoveObject(this);
        }
        break;

    case 2:
        if (move == false)
        {
            Speed = 5.f;
            m_Position.x -= Speed;
            if (m_Position.x <= 10)
                move = true;
        }

        if (move == true)
        {
            move = true;
            Speed = 6.f;

            m_Position.x += Speed;

            if (time - StartTime >= delay)
            {
                Ogr->KeepObject(new MonsterBullet(m_Position, 1), "MonsterBullet");
                StartTime = time;
            }
        }
      
        break;
    }

    
    if (Hp <= 0)
    {
        Ogr->RemoveObject(this);
        Ogr->KeepObject(new EffectMgr(L"Painting/Diee/", 1, 2, 6, m_Position), "Effect");
        RankMgr::GetInst()->AddScore(30);
        int Level = ExpMgr::GetInst()->GetLevel();
        if (Level < 5)
        {
            ExpMgr::GetInst()->AddExp(20);
        }
        int random = rand() % 19 + 1;

        if (random == 1 && Level < 5)
        {
            Ogr->KeepObject(new Level_Item(m_Position), "LevelUp");

        }
        if (random == 2)
        {
            Ogr->KeepObject(new Hill(m_Position), "Item_Hill");

        }
        if (random == 3)
        {
            Ogr->KeepObject(new ResetSkill(m_Position), "ResetSkill");
        }
    }
   
    
}

void Minion::Render()
{
    Vec2 vCameraPos = SIngletonC::GetInst()->GetPosition();

    TCHAR szHp[32] = L"";
    int m_Hp = Hp;
    wsprintf(szHp, L"Hp : %d", m_Hp);

    Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
    Matrix matFont;

    D3DXMatrixTranslation(&matFont, m_Position.x + vCameraPos.x, m_Position.y - 50, 0);
    Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
    Renderer::GetInst()->GetMonsterFont()->DrawTextW(Renderer::GetInst()->GetSprite(),
        szHp, 32, NULL, NULL, D3DCOLOR_ARGB(255, 255, 0, 0));
    Renderer::GetInst()->GetSprite()->End();
    m_Minion->Render();

    m_Minion->R = 255;
    m_Minion->G = 255;
    m_Minion->B = 255;
}

void Minion::OnCollision(Object* obj, std::string tag)
{
    if (tag == "Bullet")
        Hp -= 5;
    if (tag == "Bullet2")
        Hp -= 6;
    if (tag == "Bullet3")
        Hp -= 7.2f;
    if (tag == "Bullet4")
        Hp -= 8.64f;
    if (tag == "Bullet5")
        Hp -= 10.368f;


    if (tag == "SBullet")
        Hp -= 2;
    if (tag == "SBullet2")
        Hp -= 2.4;
    if (tag == "SBullet3")
        Hp -= 2.88;
    if (tag == "SBullet4")
        Hp -= 3.456;
    if (tag == "SBullet5")
        Hp -= 4.1472;
    if (tag == "Meteor")
        Hp -= 0.5f;

    if (tag == "Boom")
        Hp -= 0.5f;

    m_Minion->R = 255;
    m_Minion->G = 31;
    m_Minion->B = 4;
}

void Minion::Draw()
{
    Vec2 MonsterHp[] =
    {
    Vec2(m_Position.x - 60,m_Position.y - 100),
    Vec2(m_Position.x * Hp,m_Position.y - 100),
    };
    g_pLine->Begin();
    g_pLine->Draw(MonsterHp, 2, D3DCOLOR_XRGB(255, 0, 0));
}

void Minion::InitProgram()
{
    LPDIRECT3DDEVICE9 pDevice = Renderer::GetInst()->GetDevice();
    D3DXCreateLine(pDevice, &g_pLine);
    g_pLine->SetWidth(55);
}