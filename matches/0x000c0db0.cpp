class Caster {
  public:
    virtual void cast();
};
class ShaderCaster : public Caster {
  public:
    virtual void cast();
};
class Inventory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int load(Caster*, unsigned __int64);
};
extern unsigned __int64 findShader(const char*);
int f(Inventory* inv, const char* name) {
    unsigned __int64 s = findShader(name);
    ShaderCaster caster;
    return inv->load(&caster, s);
}