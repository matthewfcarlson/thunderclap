extern "C" char DAT_00427534[];
struct LocomotionDriver {
    void* vf;
    char pad[0x1c];
    int a;
    int b;
    void InitA(LocomotionDriver*);
    void InitB(LocomotionDriver*);
    LocomotionDriver* Copy(LocomotionDriver*);
};
extern int gCount_22aa50;
extern int gMax_22aa50;
LocomotionDriver* LocomotionDriver::Copy(LocomotionDriver* src) {
    InitA(src);
    vf = (void*)((int)DAT_00427534);
    InitB(src);
    a = src->a;
    b = src->b;
    ++gCount_22aa50;
    if (gCount_22aa50 > gMax_22aa50)
        gMax_22aa50 = gCount_22aa50;
    return this;
}