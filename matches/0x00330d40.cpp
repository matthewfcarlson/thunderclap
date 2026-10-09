typedef unsigned int u32;
class Base {
  public:
    void Init(u32);
};
extern int vtableSymbol;
class Shader : public Base {
  public:
    char p[0x94];
    u32 x94;
    u32 x98;
    u32 x9c;
    char q[0xe0 - 0xa0];
    u32 xe0;
    u32 xe4;
    u32 xe8;
    Shader* Run(u32);
};
Shader* Shader::Run(u32 arg) {
    Init(arg);
    x94 = 0;
    x98 = 0;
    xe0 = 0;
    x9c = 0;
    *(int**)this = &vtableSymbol;
    xe4 = 4;
    xe8 = 0x3c03126f;
    return this;
}