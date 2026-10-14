// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method5<HUDOverlay,int,int,const_char_*,math::Vector,math::Vector,math::Vector>::vfunc_2 @ 0x000cf350
struct Vec_cf350 {
    unsigned int x, y, z;
};

class HUDOverlay {
public:
    int Act(int a1, const char *a2, Vec_cf350 v3, Vec_cf350 v4, Vec_cf350 v5);
};

typedef int (HUDOverlay::*ActFn_cf350)(int, const char *, Vec_cf350, Vec_cf350, Vec_cf350);

struct Args_cf350 {
    int a1;
    const char *a2;
    Vec_cf350 v3;
    Vec_cf350 v4;
    Vec_cf350 v5;
};

class Function {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

class Method5 : public Function {
public:
    virtual void vfunc_2(HUDOverlay *obj, Args_cf350 *args, int *out);
    char pad[0x1c - 4];
    ActFn_cf350 mFn;
};

void Method5::vfunc_2(HUDOverlay *obj, Args_cf350 *args, int *out)
{
    ActFn_cf350 fn = mFn;
    int r = (obj->*fn)(args->a1, args->a2, args->v3, args->v4, args->v5);
    if (out)
        *out = r;
}
