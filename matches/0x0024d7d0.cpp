typedef unsigned __int64 U64;
extern "C" U64 __cdecl findThing(const char*, int, int);
class Base {
  public:
    Base(const U64&, const U64&, unsigned int, int, int);
    virtual void f();
};
class ListenerEffectXBoxType : public Base {
  public:
    ListenerEffectXBoxType();
    virtual void f();
};
ListenerEffectXBoxType::ListenerEffectXBoxType()
    : Base(findThing("Data_Effect", 0, 0), findThing("ListenerEffectXBox", 0, 0), 0x1000100, 0x58, 8) {}
