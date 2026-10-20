struct CSPManager {
    void FUN_001e0000_callback(int, float, float, float);
};
struct Arguments {
    int id;
    float first;
    float second;
    float third;
};
struct Method4 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CSPManager* manager, Arguments* arguments, void* unused);
    char padding[0x18];
    void (CSPManager::*callback)(int, float, float, float);
};
void Method4::vfunc_2(CSPManager* manager, Arguments* arguments, void* unused) {
    int* p = (int*)arguments;
    int id = *p++;
    float first = *(float*)p++;
    float second = *(float*)p++;
    float third = *(float*)p++;
    (manager->*callback)(id, first, second, third);
}