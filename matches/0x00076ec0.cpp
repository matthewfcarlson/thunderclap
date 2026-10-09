struct TrackFactoryTemplate_CJumpTrack {
    void* vtable;
    int vfunc_0();
    int vfunc_1();
    int vfunc_2();
    int vfunc_3();
    int vfunc_4();
    int vfunc_5();
};
struct Jump {
    int construct();
};
extern "C" void* __cdecl alloc_54(unsigned int);
int TrackFactoryTemplate_CJumpTrack::vfunc_5() {
    Jump* p = (Jump*)alloc_54(0x54);
    if (p)
        return p->construct();
    return 0;
}