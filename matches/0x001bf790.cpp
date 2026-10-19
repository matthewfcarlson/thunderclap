struct CSubtitleManager {
    void FUN_001bf790(float, float, float);
};
struct Float3 {
    float x, y, z;
};
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Method3 : Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CSubtitleManager*, const Float3*, void*);
    char padding[0x18];
    void (CSubtitleManager::*method)(float, float, float);
};
void Method3::vfunc_2(CSubtitleManager* manager, const Float3* values, void* unused) {
    const Float3* v = values;
    volatile unsigned int& x = *(volatile unsigned int*)&values;
    x = *(const unsigned int*)&v->x;
    (manager->*method)(*(float*)&values, v->y, v->z);
}