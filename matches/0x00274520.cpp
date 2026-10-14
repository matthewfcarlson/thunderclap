struct Obj8_274520 {
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
struct Obj2_274520 {
    virtual void v0();
    virtual void v1();
};
struct Drive {
    int x;
    Obj2_274520 b;
    int pad;
    Obj8_274520* a;
    int pad2[2];
    int z;
};
struct Data_274520 {
    unsigned int v[21];
};
class DriveMediaRequest {
  public:
    char pad[8];
    Drive* d;
    Data_274520* dst;
    int vfunc_1();
};
int DriveMediaRequest::vfunc_1() {
    Obj8_274520* a = d->a;
    a->v7();
    Data_274520* p = (Data_274520*)a->Get();
    *dst = *p;
    d->b.v0();
    d->z = 0;
    d->b.v1();
    return 1;
}
