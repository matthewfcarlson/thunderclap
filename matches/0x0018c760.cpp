class Sub { public: void initSub(); };
class PropSetStateByNameTrack { public: void baseInit(); char pad[0x18]; Sub sub; };
extern void* __cdecl operator_new(unsigned int);
class Factory { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual PropSetStateByNameTrack* vfunc_5(); };
PropSetStateByNameTrack* Factory::vfunc_5() {
    PropSetStateByNameTrack* p = (PropSetStateByNameTrack*)operator_new(0x20);
    if (p) {
        p->baseInit();
        *(unsigned long*)p = 0x4192fc;
        *(unsigned long*)((char*)p + 0xc) = 0;
        *(unsigned long*)((char*)p + 0x10) = 0xffffffff;
        p->sub.initSub();
        *(unsigned long*)((char*)p + 8) = 1;
        return p;
    }
    return 0;
}
