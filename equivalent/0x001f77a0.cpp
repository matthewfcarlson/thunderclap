// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method3<CEffectManager,int,const_char_*,math::Vector,math::Vector>::vfunc_2 @ 0x001f77a0
struct Vector { float x, y, z; };
class CEffectManager {
  public:
    int Dummy(const char* name, Vector a, Vector b);
};
struct Args_1f77a0 {
    const char* name;
    Vector a;
    Vector b;
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Method3 : public Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void FUN_001f77a0(CEffectManager* obj, Args_1f77a0* args, int* result);
    char pad[0x1c - 4];
    int (CEffectManager::*fn)(const char*, Vector, Vector);
};
void Method3::FUN_001f77a0(CEffectManager* obj, Args_1f77a0* args, int* result) {
    int r = (obj->*fn)(args->name, args->a, args->b);
    if (result)
        *result = r;
}
