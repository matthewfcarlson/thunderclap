// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Function4<bool,math::Vector,math::Vector,math::Vector,math::Vector>::vfunc_2 @ 0x00087030
struct Vector {
    int x, y, z;
};

struct Args {
    Vector v[4];
};

typedef bool (__cdecl *Fn4)(Vector, Vector, Vector, Vector);

class Function {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

class Function4 : public Function {
public:
    virtual void vfunc_2(void *unused, Args *args, bool *out);
    char pad[0x1c - 4];
    Fn4 fn;                   // 0x1c
};

void Function4::vfunc_2(void *unused, Args *args, bool *out)
{
    bool r = fn(args->v[0], args->v[1], args->v[2], args->v[3]);
    if (out)
        *out = r;
}
