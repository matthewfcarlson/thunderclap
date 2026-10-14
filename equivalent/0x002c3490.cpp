// STATUS: equivalent (tools/equiv.py level 3: 20018 inputs, branch coverage 6/6)
// pure3d::PointCamera::vfunc_26 @ 0x002c3490
extern "C" double fabs(double);

struct Vec3 {
    float x, y, z;
    void FUN_0022d180();
};

struct Mat4 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bab0(float angle);
    void FUN_0022bec0(Vec3* dir, Vec3* up);
    void FUN_0022ca90(Mat4* a, Mat4* b);
    void FUN_0022c120();
};

namespace pure3d {

class PointCamera {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(); virtual void vfunc_25();
    virtual void vfunc_26();
    char pad04[0x4c - 4];
    Mat4 camera;
    Mat4 view;
    char dirty;
    char padcd[3];
    Vec3 eye;
    Vec3 target;
    Vec3 up;
    float roll;
};

void PointCamera::vfunc_26()
{
    Mat4 look;
    look.FUN_0022b980();
    Vec3 dir;
    dir.x = target.x - eye.x;
    dir.y = target.y - eye.y;
    dir.z = target.z - eye.z;
    dir.FUN_0022d180();
    float d = (float)fabs(dir.z * up.z + dir.y * up.y + dir.x * up.x);
    float t = (float)fabs(d - 1.0f);
    if (t <= 1e-05f) {
        Vec3 alt;
        if (dir.y == 0.0f && dir.z == 0.0f) {
            alt.x = 0.0f;
            alt.y = 1.0f;
            alt.z = 0.0f;
        } else {
            alt.x = 1.0f;
            alt.y = 0.0f;
            alt.z = 0.0f;
        }
        look.FUN_0022bec0(&dir, &alt);
    } else {
        look.FUN_0022bec0(&dir, &up);
    }
    Mat4 rot;
    rot.FUN_0022b980();
    rot.FUN_0022bab0(roll);
    view.FUN_0022ca90(&rot, &look);
    view.m[12] = eye.x;
    view.m[13] = eye.y;
    view.m[14] = eye.z;
    camera = view;
    camera.FUN_0022c120();
    dirty = 1;
}

}
