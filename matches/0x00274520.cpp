struct Obj8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    unsigned int* Get();
};
struct Obj2 {
    virtual void v0();
    virtual void v1();
};
struct Drive {
    int x;
    Obj2 b;
    int pad;
    Obj8* a;
    int pad2[2];
    int z;
};
struct Data {
    unsigned int v[21];
};
class DriveMediaRequest {
  public:
    char pad[8];
    Drive* d;
    Data* dst;
    int vfunc_1();
};
int DriveMediaRequest::vfunc_1() {
    Obj8* a = d->a;
    a->v7();
    Data* p = (Data*)a->Get();
    *dst = *p;
    d->b.v0();
    d->z = 0;
    d->b.v1();
    return 1;
}
