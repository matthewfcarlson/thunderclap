typedef unsigned int u32;
extern void* __cdecl FUN_00247530(void*);
extern u32 clipVftable;
extern char allocatorGlobal;
namespace audio {
class Clip { public: u32 vft; char pad[0x24]; u32 field28; void init(void*); };
class ClipType { public: virtual void f0(); virtual void f1(); virtual void* vfunc_2(); };
void* ClipType::vfunc_2() {
    Clip* p = (Clip*)FUN_00247530(&allocatorGlobal);
    if (p != 0) {
        p->init(&allocatorGlobal);
        p->vft = (u32)&clipVftable;
        p->field28 = 0;
        return p;
    }
    return 0;
}
}