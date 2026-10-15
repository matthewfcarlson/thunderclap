namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class CSPManager {
  public:
    void doIt(const char*, const char*, math::Vector);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CSPManager*, void*, void*);
};
class Method3 : public Function {
  public:
    char pad[0x1c - 4];
    void (CSPManager::*fn)(const char*, const char*, math::Vector);
    virtual void vfunc_2(CSPManager*, void*, void*);
};
void Method3::vfunc_2(CSPManager* obj, void* raw, void*) {
    const char** p = (const char**)raw;
    const char* a = *p++;
    const char* b = *p++;
    math::Vector v = *(math::Vector*)p;
    (obj->*fn)(a, b, v);
}
