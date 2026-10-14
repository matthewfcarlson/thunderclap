extern "C" __int64 __cdecl getid(const char*, int, int);
struct Id_24dbe0 {
    __int64 value;
    Id_24dbe0(const char* s) : value(getid(s, 0, 0)) {}
};
class Base_24dbe0 {
  public:
    virtual void f();
    Base_24dbe0(const Id_24dbe0&, const Id_24dbe0&, int, int, int);
};
class ListenerEffectPspType : public Base_24dbe0 {
  public:
    virtual void f();
    ListenerEffectPspType();
};
ListenerEffectPspType::ListenerEffectPspType()
    : Base_24dbe0(Id_24dbe0("Data_Effect"), Id_24dbe0("ListenerEffectPsp"), 0x1000104, 0x38, 8) {}
