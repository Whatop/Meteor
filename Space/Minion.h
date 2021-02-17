#pragma once
class Minion : public Object
{
private:
    Sprite* m_Minion;
    LPDIRECT3DDEVICE9 g_pd3dDevice;
    LPD3DXLINE g_pLine;

    bool boo;
    float Hp;
    int num;
    bool a, b, move;
    int m_Type;
public:
    float Speed;
    int delay;
    Minion(Vec2 Pos,int type);
    ~Minion();

    void Update(float time);
    void Render();
    void OnCollision(Object* obj, std::string tag);
    void Draw();
    void InitProgram();
};