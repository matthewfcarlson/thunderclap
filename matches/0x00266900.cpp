class Ref_266900 {
  public:
    virtual void f0();
    virtual void f1();
};
extern char vtLoad_266900[];
extern char vtRef_266900[];
namespace content { class LoadRequest {
  public:
    int vt;
    char p[0x14];
    Ref_266900* a;
    Ref_266900* c;
    char q[0x104];
    Ref_266900* b;
    LoadRequest* vfunc_2(bool);
}; }
void thunk(content::LoadRequest*);
content::LoadRequest* content::LoadRequest::vfunc_2(bool d) {
    vt = (int)vtLoad_266900;
    if (a)
        a->f1();
    if (b)
        b->f1();
    if (c)
        c->f1();
    vt = (int)vtRef_266900;
    if (d & 1)
        thunk(this);
    return this;
}