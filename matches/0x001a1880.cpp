class Sub {
  public:
    virtual void F();
    virtual void G();
    Sub();
    char pad[0xdc];
};
class Result {
  public:
    Sub* Convert();
};
struct Base {
    virtual void V();
    Base();
    char pad[0x18];
};
Result* __cdecl MakeResult(Sub*, int, int, int, int);
extern "C" void* memcpy(void*, const void*, unsigned int);
class LuaAction : public Base {
  public:
    LuaAction(int a, int b, Sub* arg);
    virtual void V();
    int m1c;
    Sub* m20;
    int m24;
    Sub sub;
};
LuaAction::LuaAction(int a, int b, Sub* arg) : m20(0), m24(0) {
    m1c = b;
    if (arg)
        arg->F();
    if (m20)
        m20->G();
    m20 = arg;
    Result* r = MakeResult(arg, 0, 0x494b44, 0x4c13d0, 0);
    if (r)
        memcpy(&sub, r->Convert(), 0xe0);
}
