void* __cdecl alloc(unsigned int);
extern int vt;
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
        *(int*)p = (int)&vt;
        p->InitB(this);
        return p;
    }
    return 0;
}
