class Thing {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual bool Check();
    virtual void Get(int*);
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void Apply(int);
};
extern float gHalf;
extern void Helper(int*, int, float);
void Thing::Apply(int x) {
    int local[3];
    if (!Check()) {
        Get(&local[0]);
        Helper(&local[0], x, gHalf);
        Apply(x);
    }
}
