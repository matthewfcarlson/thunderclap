extern "C" char DAT_00429d1c[];
typedef unsigned int u32;
struct E {
    void init();
};
struct S {
    void setup(char*, int);
};
extern void* alloc(void*);
extern char pool[1];
extern char name[1];
class SeqEventStopTrackType {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void* vfunc_3();
};
void* SeqEventStopTrackType::vfunc_3() {
    E* p = (E*)alloc(pool);
    if (p) {
        p->init();
        *(u32*)p = ((int)DAT_00429d1c);
        ((u32*)p)[2] = 0;
        ((u32*)p)[3] = 0;
        ((S*)((char*)p + 0x10))->setup(name, 2);
        *((char*)p + 0x1c) = 0;
        return p;
    }
    return 0;
}