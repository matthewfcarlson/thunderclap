class Sub_1a1880 {
  public:
    virtual void F();
    virtual void G();
    Sub_1a1880();
    char pad[0xdc];
};
class Result_1a1880 {
  public:
    Sub_1a1880* Convert();
};
struct Base_1a1880 {
    virtual void V();
    Base_1a1880();
    char pad[0x18];
};
Result_1a1880* __cdecl MakeResult(Sub_1a1880*, int, int, int, int);
extern "C" void* memcpy(void*, const void*, unsigned int);
class LuaAction : public Base_1a1880 {
  public:
    LuaAction(int a, int b, Sub_1a1880* arg);
    virtual void V();
    int m1c;
    Sub_1a1880* m20;
    int m24;
    Sub_1a1880 sub;
};
LuaAction::LuaAction(int a, int b, Sub_1a1880* arg) : m20(0), m24(0) {
    m1c = b;
    if (arg)
        arg->F();
    if (m20)
        m20->G();
    m20 = arg;
    Result_1a1880* r = MakeResult(arg, 0, 0x494b44, 0x4c13d0, 0);
    if (r)
        memcpy(&sub, r->Convert(), 0xe0);
}
