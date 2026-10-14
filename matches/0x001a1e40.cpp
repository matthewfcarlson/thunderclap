extern "C" char DAT_0041c318[];
struct LuaTrack {
    void* vf;
    char pad[8];
    int x;
    int y;
    int z;
    int q;
    void initialize();
};
extern void* alloc(unsigned int);
class Factory_1a1e40 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual LuaTrack* vfunc_5();
};
LuaTrack* Factory_1a1e40::vfunc_5() {
    LuaTrack* p = (LuaTrack*)alloc(0x1c);
    if (p) {
        p->initialize();
        p->vf = (void*)((int)DAT_0041c318);
        p->x = 0;
        p->y = (int)0xbf800000;
        p->z = 0;
        p->q = 0;
        return p;
    }
    return 0;
}