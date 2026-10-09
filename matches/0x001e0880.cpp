struct Vector { float x, y, z; };
struct CSPManager { int dummy; };
struct Arg { Vector v; float f; };
class Method2 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CSPManager* obj, Arg* a, bool* out);
    char pad[0x1c - 4];
    bool (CSPManager::*mFn)(Vector, float);
};
void Method2::vfunc_2(CSPManager* obj, Arg* a, bool* out) {
    bool (CSPManager::*fn)(Vector, float) = mFn;
    Vector v = a->v;
    float f = a->f;
    bool r = (obj->*fn)(v, f);
    if (out) *out = r;
}
