// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method4<CRenderManager,unsigned_int,const_char_*,math::Vector,math::Vector,float>::vfunc_2 @ 0x001ba120
struct Vec {
    unsigned x, y, z;
};
struct Args {
    const char *name;
    Vec from;
    Vec to;
    unsigned radius;
};
class CRenderManager {
  public:
    unsigned Check(const char *name, Vec from, Vec to, unsigned radius);
};
typedef unsigned (CRenderManager::*CheckFn)(const char *, Vec, Vec, unsigned);
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Method4 : public Function {
  public:
    virtual void vfunc_2(CRenderManager *obj, Args *args, unsigned *out);
    char pad[0x1c - 4];
    CheckFn mFn;
};
void Method4::vfunc_2(CRenderManager *obj, Args *args, unsigned *out)
{
    CheckFn fn = mFn;
    unsigned r = (obj->*fn)(args->name, args->from, args->to, args->radius);
    if (out)
        *out = r;
}
