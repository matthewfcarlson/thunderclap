// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method4<CTriggerVolumeManager,bool,const_char_*,math::Vector,math::Vector,float>::vfunc_2 @ 0x001fed30
struct Vec {
    unsigned x, y, z;
};
struct Args {
    const char *name;
    Vec from;
    Vec to;
    unsigned radius;
};
class CTriggerVolumeManager {
  public:
    bool Check(const char *name, Vec from, Vec to, unsigned radius);
};
typedef bool (CTriggerVolumeManager::*CheckFn)(const char *, Vec, Vec, unsigned);
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Method4 : public Function {
  public:
    virtual void vfunc_2(CTriggerVolumeManager *obj, Args *args, bool *out);
    char pad[0x1c - 4];
    CheckFn mFn;
};
void Method4::vfunc_2(CTriggerVolumeManager *obj, Args *args, bool *out)
{
    CheckFn fn = mFn;
    bool r = (obj->*fn)(args->name, args->from, args->to, args->radius);
    if (out)
        *out = r;
}
