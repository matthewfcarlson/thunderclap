class Item {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
class Ref {
  public:
    virtual void a();
    virtual void Destroy();
};
class Obj {
  public:
    char pad0[0x10];
    unsigned int count;
    unsigned int n;
    char pad1c[4];
    Item** items;
    char pad24[8];
    void* entries;
    void Clear();
};
void Obj::Clear() {
    unsigned int i = 0;
    while (i < count) {
        items[i]->f();
        ++i;
    }
    unsigned int j = 0;
    unsigned int off = 0;
    while (j < n) {
        Ref** p = (Ref**)((char*)entries + off + 0x40);
        if (*p) {
            (*p)->Destroy();
            *p = 0;
        }
        p = (Ref**)((char*)entries + off + 0x44);
        if (*p) {
            (*p)->Destroy();
            *p = 0;
        }
        ++j;
        off += 0x48;
    }
    n = 0;
}