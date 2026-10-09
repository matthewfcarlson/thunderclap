void* __cdecl FUN_0008d690(unsigned int);
class TrackFactoryTemplate { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void* vfunc_5(); };
struct Obj { int pad0[5]; void Init(); };
void* TrackFactoryTemplate::vfunc_5() {
    Obj* p = (Obj*)FUN_0008d690(0x14);
    if (p) {
        p->Init();
        *(int*)p = 0x3fc10c;
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 8) = 1;
        return p;
    }
    return 0;
}
