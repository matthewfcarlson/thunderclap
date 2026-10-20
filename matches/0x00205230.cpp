struct CWorldStreamManager {};
struct Method3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CWorldStreamManager* manager, const float* args, int* result);
    char padding[0x18];
    int (CWorldStreamManager::*callback)(float, float, float);
};
void Method3::vfunc_2(CWorldStreamManager* manager, const float* args, int* result) {
    int (CWorldStreamManager::*fn)(float, float, float) = callback;
    float a = args[0], b = args[1], c = args[2];
    int value = (manager->*fn)(a, b, c);
    if (result)
        *result = value;
}