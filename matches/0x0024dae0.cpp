typedef unsigned __int64 U64_24dae0;
extern U64_24dae0 __cdecl lookup(const char*, int, int);
class MetaEntityType_24dae0 {
  public:
    virtual void f();
    MetaEntityType_24dae0(const U64_24dae0&, const U64_24dae0&, int, int, int);
};
class ListenerEffectWin32Type : public MetaEntityType_24dae0 {
  public:
    virtual void g();
    ListenerEffectWin32Type();
};
ListenerEffectWin32Type::ListenerEffectWin32Type()
    : MetaEntityType_24dae0(lookup("Data_Effect", 0, 0), lookup("ListenerEffectWin32", 0, 0), 0x1000103, 0x30, 8) {}