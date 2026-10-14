class Scenegraph {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual int vfunc_4();
};
class Obj_297130 {
  public:
    int helper(Scenegraph*);
};
extern Obj_297130* alloc(int);
int Scenegraph::vfunc_4() {
    Obj_297130* p = alloc(0x48);
    if (p)
        return p->helper(this);
    return 0;
}