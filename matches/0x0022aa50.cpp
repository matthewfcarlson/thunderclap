struct LocomotionDriver {
    void* vf;
    char pad[0x1c];
    int a;
    int b;
    void InitA(LocomotionDriver*);
    void InitB(LocomotionDriver*);
    LocomotionDriver* Copy(LocomotionDriver*);
};
extern int gCount;
extern int gMax;
LocomotionDriver* LocomotionDriver::Copy(LocomotionDriver* src) {
    InitA(src);
    vf = (void*)0x427534;
    InitB(src);
    a = src->a;
    b = src->b;
    ++gCount;
    if (gCount > gMax)
        gMax = gCount;
    return this;
}