struct V {
    int a, b, c;
};
class CollisionVolume {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual V* f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14(CollisionVolume*);
    char pad[0x40];
};
class CollisionCylinder : public CollisionVolume {
  public:
    char data[0x40];
    virtual void vfunc14(CollisionCylinder*);
};
void CollisionCylinder::vfunc14(CollisionCylinder* p) {
    CollisionVolume::f14((CollisionVolume*)p);
    V* a = f4();
    V* b = p->f4();
    *b = *a;
    char* s = (char*)this;
    char* d = (char*)p;
    *(int*)(d + 0x44) = *(int*)(s + 0x44);
    *(int*)(d + 0x48) = *(int*)(s + 0x48);
    *(int*)(d + 0x4c) = *(int*)(s + 0x4c);
    *(int*)(d + 0x50) = *(int*)(s + 0x50);
    *(int*)(d + 0x54) = *(int*)(s + 0x54);
    d[0x58] = s[0x58];
    *(int*)(d + 0x70) = *(int*)(s + 0x70);
    *(int*)(d + 0x74) = *(int*)(s + 0x74);
    *(int*)(d + 0x78) = *(int*)(s + 0x78);
    *(int*)(d + 0x7c) = *(int*)(s + 0x7c);
    *(int*)(d + 0x80) = *(int*)(s + 0x80);
    *(int*)(d + 0x60) = *(int*)(s + 0x60);
}
