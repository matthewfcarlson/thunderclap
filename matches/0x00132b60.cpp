typedef unsigned int u32;
extern "C" void* __cdecl alloc(unsigned int);
class Track { public: Track(); virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); };
class Factory { public: Track* vfunc_5(); };
Track* Factory::vfunc_5() {
    Track* p = (Track*)alloc(0x14);
    if (p) {
        p->Track::Track();
        *(u32*)p = 0x4112e4;
        *(u32*)((char*)p + 0xc) = 0;
        *(u32*)((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}