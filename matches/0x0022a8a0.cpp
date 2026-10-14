void* __cdecl alloc(unsigned int);
extern int vt_22a8a0;
struct RestPoseDriver {
    int pad;
    void InitA(RestPoseDriver*);
    void InitB(RestPoseDriver*);
    RestPoseDriver* vfunc_5();
};
RestPoseDriver* RestPoseDriver::vfunc_5() {
    RestPoseDriver* p = (RestPoseDriver*)alloc(0x20);
    if (p) {
        p->InitA(this);
        *(int*)p = (int)&vt_22a8a0;
        p->InitB(this);
        return p;
    }
    return 0;
}
