class Ref {
  public:
    virtual void A();
    virtual void Release();
};
extern int toonVftable;
class Shader {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    char pad[0x7c];
    Ref* m80;
    Ref* m84;
    Ref* m88;
    void Reset();
};
class Next {
  public:
    void Go();
};
void Shader::Reset() {
    *(int*)this = (int)&toonVftable;
    if (m88)
        m88->Release();
    if (m80)
        m80->Release();
    if (m84)
        m84->Release();
    ((Next*)this)->Go();
}
