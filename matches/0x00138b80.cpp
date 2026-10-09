extern int type1, type2;
class Built {
  public:
    int make(int, int);
};
class HoverTrack {
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
    virtual int vfunc_10(int, int, int);
    char pad[0x10];
    int member14;
};
extern int __cdecl Check(void*, int, int, int, int);
extern Built* __cdecl Allocate(int);
int HoverTrack::vfunc_10(int a, int b, int c) {
    if (Check((void*)c, 0, (int)&type1, (int)&type2, 0)) {
        Built* p = Allocate(0x24);
        if (p) {
            int m = member14;
            return p->make(m, c);
        }
    }
    return 0;
}
