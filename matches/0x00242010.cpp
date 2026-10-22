extern "C" unsigned __int64 __cdecl lookup(const char*, int, int);
extern char mixName[];
extern char otherName[];
class EntityType_242010 {
  public:
    virtual void f();
    EntityType_242010(const unsigned __int64&, const unsigned __int64&, int, int, int);
};
class MixType_242010 : public EntityType_242010 {
  public:
    MixType_242010();
    virtual void f();
};
MixType_242010::MixType_242010() : EntityType_242010(lookup(otherName, 0, 0), lookup(mixName, 0, 0), 0x1000002, 0x50, 8) {}