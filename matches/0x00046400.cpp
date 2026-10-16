class CSPHulkProp;
class Caster {
  public:
    Caster() {}
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
class Loader {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int Load(Caster*, int, int);
    int Go(int x, int y);
};
int Loader::Go(int x, int y) {
    Caster caster;
    return Load(&caster, x, y);
}
