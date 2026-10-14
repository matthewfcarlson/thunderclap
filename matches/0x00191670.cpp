extern int RTTI1_191670, RTTI2;
class TankLocomotionTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int v10(int a, int b, int c);
};
class Created_191670 {
  public:
    int init(TankLocomotionTrack*, int);
};
extern int typecheck(void*, int, int*, int*, int);
extern Created_191670* alloc(int);
int TankLocomotionTrack::v10(int a, int b, int c) {
    if (typecheck((void*)c, 0, &RTTI1_191670, &RTTI2, 0)) {
        Created_191670* p = alloc(0xa4);
        if (p)
            return p->init(this, c);
    }
    return 0;
}