// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method4<CRenderManager,unsigned_int,const_char_*,math::Vector,math::Vector,float>::vfunc_2 @ 0x001ba120
struct Vec_1ba120 {
    unsigned x, y, z;
};
struct Args_1ba120 {
    const char *name;
    Vec_1ba120 from;
    Vec_1ba120 to;
    unsigned radius;
};
class CRenderManager {
  public:
    unsigned Check(const char *name, Vec_1ba120 from, Vec_1ba120 to, unsigned radius);
};
typedef unsigned (CRenderManager::*CheckFn_1ba120)(const char *, Vec_1ba120, Vec_1ba120, unsigned);
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Method4 : public Function {
  public:
    virtual void vfunc_2(CRenderManager *obj, Args_1ba120 *args, unsigned *out);
    char pad[0x1c - 4];
    CheckFn_1ba120 mFn;
};
void Method4::vfunc_2(CRenderManager *obj, Args_1ba120 *args, unsigned *out)
{
    CheckFn_1ba120 fn = mFn;
    unsigned r = (obj->*fn)(args->name, args->from, args->to, args->radius);
    if (out)
        *out = r;
}
