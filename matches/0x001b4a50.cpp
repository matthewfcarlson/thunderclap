class Ref {
  public:
    virtual void a();
    virtual void release();
};
class Elem {
  public:
    void clear();
};
class Other {
  public:
    void clean();
};
class Obj {
  public:
    char pad0[8];
    Other* other;
    Ref* ref;
    char pad1[0x3b8 - 0x10];
    char pad2[0x4f0 - 0x3b8];
    int x, y, z;
    void reset();
};
void Obj::reset() {
    volatile Obj* v = this;
    v->x = 0;
    v->y = 0;
    v->z = 0;
    Ref* r = v->ref;
    if (r) {
        r->release();
        ref = 0;
    }
    other->clean();
    Elem* p = (Elem*)((char*)this + 0x3b8);
    int n = 4;
    do {
        p->clear();
        p = (Elem*)((char*)p - 0x138);
        --n;
    } while (n);
}