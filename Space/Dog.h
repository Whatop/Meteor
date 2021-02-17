#pragma once
class Dog : public Object
{
private:
    Sprite* m_Dog;
    LPDIRECT3DDEVICE9 g_pd3dDevice;
    LPD3DXLINE g_pLine;

    float Hp;
    int num;
    bool a, b, move;
    bool boo;
public:
    float Speed;
    int delay,m_Type;
    Dog(float x,float y,int type);
    ~Dog();

    void Update(float time);
    void Render();
    void OnCollision(Object* obj, std::string tag);
    void Draw();
    void InitProgram();
};