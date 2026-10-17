// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// physics::SimpleFilterAbs3D::vfunc_1 @ 0x00319b50
namespace physics {
struct Vec3 { float x, y, z; };
class SimpleFilter3D {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(const Vec3*, unsigned int);
    virtual void vfunc_2();
};
class SimpleFilterAbs3D : public SimpleFilter3D {
public:
    virtual void vfunc_1(const Vec3* input, unsigned int param);
};
void SimpleFilterAbs3D::vfunc_1(const Vec3* input, unsigned int param)
{
    union Bits { float value; unsigned int bits; } x, y, z;
    x.value = input->x;
    y.value = input->y;
    z.value = input->z;
    x.bits &= 0x7fffffff;
    y.bits &= 0x7fffffff;
    z.bits &= 0x7fffffff;
    Vec3 absolute = {x.value, y.value, z.value};
    SimpleFilter3D::vfunc_1(&absolute, param);
}
}