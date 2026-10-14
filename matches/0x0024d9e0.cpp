typedef unsigned __int64 U64_24d9e0;
U64_24d9e0 __cdecl Lookup(const char*, int, int);
class Base_24d9e0 {
  public:
    virtual void f();
    Base_24d9e0(const U64_24d9e0&, const U64_24d9e0&, int, int, int);
};
class ListenerEffectPs2Type : public Base_24d9e0 {
  public:
    virtual void f();
    ListenerEffectPs2Type();
};
ListenerEffectPs2Type::ListenerEffectPs2Type()
    : Base_24d9e0(Lookup("Data_Effect", 0, 0), Lookup("ListenerEffectPs2", 0, 0), 0x1000101, 0x38, 8) {}