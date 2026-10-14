typedef unsigned __int64 U64;
extern U64 __cdecl lookup(const char*, int, int);
class Base {
  public:
    virtual void f();
    Base(const U64&, const U64&, int, int, int);
};
class ListenerEffectWin32Type : public Base {
  public:
    virtual void g();
    ListenerEffectWin32Type();
};
ListenerEffectWin32Type::ListenerEffectWin32Type()
    : Base(lookup("Data_Effect", 0, 0), lookup("ListenerEffectWin32", 0, 0), 0x1000103, 0x30, 8) {}