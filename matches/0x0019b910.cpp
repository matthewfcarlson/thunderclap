// Same code shape as 0x0010bd40 (propagated; names are from that function)
class FaceTargetTrack {
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
    virtual int vfunc_10(int a, int b, int c);
};
class Params {
  public:
    int x;
};
extern Params TypeA_19b910;
extern Params TypeB_19b910;
int __cdecl Check(void*, int, Params*, Params*, int);
class Object {
  public:
    int Init(FaceTargetTrack*, int);
};
Object* __cdecl Alloc(int);
int FaceTargetTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_19b910, &TypeB_19b910, 0);
    if (result) {
        Object* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}