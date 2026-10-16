class Track {};
class Caster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
extern "C" void* __cdecl DynamicCast(void*, int, void*, void*, int);
class PropCaster : public Caster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
bool PropCaster::Check(void* p) {
    return DynamicCast(p, 0, (void*)0x49850c, (void*)0x4be240, 0) != 0;
}