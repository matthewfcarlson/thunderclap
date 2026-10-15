struct Vector {
    float x, y, z;
    Vector() {}
    Vector(const Vector& v) : x(v.x), y(v.y), z(v.z) {}
};
class CSPManager {
  public:
    Vector method(const char*);
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void vfunc_2(void*, const char**, Vector*);
};
class Closure1 : public Function {
  public:
    char pad[0x18];
    Vector (CSPManager::*fn)(const char*);
    CSPManager* obj;
    virtual void vfunc_2(void*, const char**, Vector*);
};
void Closure1::vfunc_2(void* unused, const char** name, Vector* out) {
    CSPManager* p = obj;
    Vector (CSPManager::*f)(const char*) = fn;
    Vector value = (p->*f)(*name);
    if (out)
        *out = value;
}