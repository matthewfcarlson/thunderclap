extern "C" __int64 __cdecl getid(const char*, int, int);
struct Id {
    __int64 value;
    Id(const char* s) : value(getid(s, 0, 0)) {}
};
class Base {
  public:
    virtual void f();
    Base(const Id&, const Id&, int, int, int);
};
class ListenerEffectPspType : public Base {
  public:
    virtual void f();
    ListenerEffectPspType();
};
ListenerEffectPspType::ListenerEffectPspType()
    : Base(Id("Data_Effect"), Id("ListenerEffectPsp"), 0x1000104, 0x38, 8) {}
