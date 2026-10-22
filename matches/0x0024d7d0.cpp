typedef unsigned __int64 U64_24d7d0;
extern "C" U64_24d7d0 __cdecl findThing(const char*, int, int);
class MetaEntityType_24d7d0 {
  public:
    MetaEntityType_24d7d0(const U64_24d7d0&, const U64_24d7d0&, unsigned int, int, int);
    virtual void f();
};
class ListenerEffectXBoxType : public MetaEntityType_24d7d0 {
  public:
    ListenerEffectXBoxType();
    virtual void f();
};
ListenerEffectXBoxType::ListenerEffectXBoxType()
    : MetaEntityType_24d7d0(findThing("Data_Effect", 0, 0), findThing("ListenerEffectXBox", 0, 0), 0x1000100, 0x58, 8) {}
