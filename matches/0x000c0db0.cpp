class DynamicCasterBase_c0db0 {
  public:
    virtual void cast();
};
class DynamicCaster_c0db0 : public DynamicCasterBase_c0db0 {
  public:
    virtual void cast();
};
class Inventory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int load(DynamicCasterBase_c0db0*, unsigned __int64);
};
extern unsigned __int64 findShader(const char*);
int f(Inventory* inv, const char* name) {
    unsigned __int64 s = findShader(name);
    DynamicCaster_c0db0 caster;
    return inv->load(&caster, s);
}