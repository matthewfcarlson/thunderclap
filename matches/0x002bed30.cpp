extern int vt1_2bed30, vt2;
extern void Free(void*);
extern void Free2(void*);
class Obj_2bed30 {
  public:
    void Fini();
};
class Ref_2bed30 {
  public:
    virtual void f0();
    virtual void Rel();
};
class Ref2 {
  public:
    virtual void Del(int);
};
class SpriteLoader_2bed30 {
  public:
    void* vptr;
    char p[0x10];
    Ref2* a14;
    Ref_2bed30* a18;
    Obj_2bed30* a1c;
    SpriteLoader_2bed30* vfunc2(unsigned char f);
};
SpriteLoader_2bed30* SpriteLoader_2bed30::vfunc2(unsigned char f) {
    Ref_2bed30* r = a18;
    vptr = &vt1_2bed30;
    r->Rel();
    if (a14)
        a14->Del(1);
    Obj_2bed30* o = a1c;
    if (o) {
        o->Fini();
        Free2(o);
    }
    vptr = &vt2;
    if (f & 1)
        Free(this);
    return this;
}
