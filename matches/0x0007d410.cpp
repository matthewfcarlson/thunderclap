namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
struct CAmbientsManager {
    void f(const char*, int, const math::Vector, const math::Vector);
};
struct Function {
    virtual void v0();
    virtual void v1();
};
struct M4_7d410 : Function {
    char pad[0x18];
    void (CAmbientsManager::*fn)(const char*, int, const math::Vector, const math::Vector);
    virtual void v0();
    virtual void v2(CAmbientsManager* o, char* a, int u);
};
void M4_7d410::v2(CAmbientsManager* o, char* a, int u) {
    char* p = a;
    const char* s = *(const char**)p;
    p += 4;
    int i = *(int*)p;
    p += 4;
    math::Vector va = *(math::Vector*)p;
    p += 12;
    math::Vector vb = *(math::Vector*)p;
    (o->*fn)(s, i, va, vb);
}