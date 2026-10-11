extern "C" char DAT_00411110[];
struct Ref {
    virtual void f0();
    virtual void f1();
};
extern void* Alloc(unsigned int);
struct Memory {
    void Init();
};
struct PostEvent_StringTrack {
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
    virtual void* vfunc_10(int, int, Ref*);
};
void PostEvent_StringTrack::v0() {}
void PostEvent_StringTrack::v1() {}
void PostEvent_StringTrack::v2() {}
void PostEvent_StringTrack::v3() {}
void PostEvent_StringTrack::v4() {}
void PostEvent_StringTrack::v5() {}
void PostEvent_StringTrack::v6() {}
void PostEvent_StringTrack::v7() {}
void PostEvent_StringTrack::v8() {}
void PostEvent_StringTrack::v9() {}
void* PostEvent_StringTrack::vfunc_10(int a, int b, Ref* param) {
    char* p = (char*)Alloc(0x24);
    if (p) {
        ((Memory*)p)->Init();
        *(void**)(p + 0x1c) = this;
        *(unsigned int*)p = ((int)DAT_00411110);
        *(unsigned int*)(p + 0x20) = 0;
        if (param)
            param->f0();
        Ref* old = *(Ref**)(p + 0x20);
        if (old)
            old->f1();
        *(Ref**)(p + 0x20) = param;
        return p;
    }
    return 0;
}