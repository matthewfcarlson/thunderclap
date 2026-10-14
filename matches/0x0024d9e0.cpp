typedef unsigned __int64 U64;
U64 __cdecl Lookup(const char*, int, int);
class Base {
  public:
    virtual void f();
    Base(const U64&, const U64&, int, int, int);
};
class ListenerEffectPs2Type : public Base {
  public:
    virtual void f();
    ListenerEffectPs2Type();
};
ListenerEffectPs2Type::ListenerEffectPs2Type()
    : Base(Lookup("Data_Effect", 0, 0), Lookup("ListenerEffectPs2", 0, 0), 0x1000101, 0x38, 8) {}