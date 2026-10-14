class Item_29bba0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
class Ref_29bba0 {
  public:
    virtual void a();
    virtual void Destroy();
};
class Obj_29bba0 {
  public:
    char pad0[0x10];
    unsigned int count;
    unsigned int n;
    char pad1c[4];
    Item_29bba0** items;
    char pad24[8];
    void* entries;
    void Clear();
};
void Obj_29bba0::Clear() {
    unsigned int i = 0;
    while (i < count) {
        items[i]->f();
        ++i;
    }
    unsigned int j = 0;
    unsigned int off = 0;
    while (j < n) {
        Ref_29bba0** p = (Ref_29bba0**)((char*)entries + off + 0x40);
        if (*p) {
            (*p)->Destroy();
            *p = 0;
        }
        p = (Ref_29bba0**)((char*)entries + off + 0x44);
        if (*p) {
            (*p)->Destroy();
            *p = 0;
        }
        ++j;
        off += 0x48;
    }
    n = 0;
}