struct Vector {
    float x, y, z;
};
class CWorldCollisionManager {
  public:
    Vector Do(Vector);
};
typedef Vector (CWorldCollisionManager::*Method_2021f0)(Vector);
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class Method1 : public Function {
    char pad[0x18];

  public:
    Method_2021f0 method;
    virtual void f2(CWorldCollisionManager* obj, const Vector* arg, Vector* out);
};
inline Vector Copy(const Vector& v) {
    Vector r;
    r.x = v.x;
    r.y = v.y;
    r.z = v.z;
    return r;
}
void Method1::f2(CWorldCollisionManager* obj, const Vector* arg, Vector* out) {
    Method_2021f0 m = method;
    Vector v = Copy((obj->*m)(*arg));
    if (out)
        *out = v;
}