// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// physics::SimpleFilterAbs3D::vfunc_0 @ 0x00319af0
namespace physics {
struct SimpleFilter3D {
    virtual unsigned char vfunc_0(unsigned int, unsigned int, unsigned int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    unsigned int x, y, z;
};
struct SimpleFilterAbs3D : SimpleFilter3D {
    virtual unsigned char vfunc_0(unsigned int a, unsigned int b, unsigned int c);
};
unsigned char SimpleFilterAbs3D::vfunc_0(unsigned int a, unsigned int b, unsigned int c) {
    if (!SimpleFilter3D::vfunc_0(a,b,c)) return 0;
    x &= 0x7fffffff;
    y &= 0x7fffffff;
    z &= 0x7fffffff;
    return 1;
}
}