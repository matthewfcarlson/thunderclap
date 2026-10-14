// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 0/0)
// pure3d::Vector2DOFChannel::vfunc_3 @ 0x0028a5b0
// 0x0028a5b0: Vector2DOFChannel::vfunc_3: read key `index`: its time, and a vector with two components keyed
namespace pure3d {

class Vector2DOFChannel {
public:
    char pad00[0x14];
    short* times;
    int axis;
    int base[3];
    int (*values)[2];
    void vfunc_3(int index, float* time, int* out);
};

void Vector2DOFChannel::vfunc_3(int index, float* time, int* out)
{
    int other[3][2] = { { 1, 2 }, { 0, 2 }, { 0, 1 } };
    *time = (float)times[index];
    out[0] = base[0];
    out[1] = base[1];
    out[2] = base[2];
    out[other[axis][0]] = values[index][0];
    out[other[axis][1]] = values[index][1];
}

}
