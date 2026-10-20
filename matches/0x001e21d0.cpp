namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
struct CSPManager {};
struct Arguments {
    math::Vector vector;
    float value;
};
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, const Arguments*, bool*);
    char padding[0x18];
    bool (CSPManager::*method)(math::Vector, float);
    CSPManager* manager;
};
void Closure2::vfunc_2(void* unused, const Arguments* arguments, bool* result) {
    CSPManager* mgr = manager;
    bool (CSPManager::*fn)(math::Vector, float) = method;
    float f = arguments->value;
    bool value = (mgr->*fn)(arguments->vector, f);
    if (result)
        *result = value;
}