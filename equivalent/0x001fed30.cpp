// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method4<CTriggerVolumeManager,bool,const_char_*,math::Vector,math::Vector,float>::vfunc_2 @ 0x001fed30
struct Vec_1fed30 {
    unsigned x, y, z;
};
struct Args_1fed30 {
    const char *name;
    Vec_1fed30 from;
    Vec_1fed30 to;
    unsigned radius;
};
class CTriggerVolumeManager {
  public:
    bool Check(const char *name, Vec_1fed30 from, Vec_1fed30 to, unsigned radius);
};
typedef bool (CTriggerVolumeManager::*CheckFn_1fed30)(const char *, Vec_1fed30, Vec_1fed30, unsigned);
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Method4 : public Function {
  public:
    virtual void vfunc_2(CTriggerVolumeManager *obj, Args_1fed30 *args, bool *out);
    char pad[0x1c - 4];
    CheckFn_1fed30 mFn;
};
void Method4::vfunc_2(CTriggerVolumeManager *obj, Args_1fed30 *args, bool *out)
{
    CheckFn_1fed30 fn = mFn;
    bool r = (obj->*fn)(args->name, args->from, args->to, args->radius);
    if (out)
        *out = r;
}
