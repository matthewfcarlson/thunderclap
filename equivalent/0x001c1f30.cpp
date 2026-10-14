// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 2/2)
// FUN_001c1f30 @ 0x001c1f30
extern "C" double __cdecl tan(double);
extern "C" double __cdecl atan(double);

struct Plane_1c1f30 {
    float a, b, c, d;
};

class Camera {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(float fov, float aspect);
    virtual void vfunc_6();
    virtual void vfunc_7(int a);
    virtual void vfunc_8();
    virtual void vfunc_9(int a);
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(int which, Plane_1c1f30 *out);
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21(int a);
};

class System_1c1f30 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual float vfunc_16();
};

extern System_1c1f30 *DAT_0052c2a4;
extern float DAT_004c5114;

class CameraState {
public:
    char pad00[8];
    Camera *camera;
    char pad0c[4];
    Plane_1c1f30 left;
    Plane_1c1f30 right;
    Plane_1c1f30 top;
    Plane_1c1f30 bottom;
    Plane_1c1f30 nearP;
    Plane_1c1f30 farP;
    char pad70[0xb0 - 0x70];
    float halfX;
    float halfY;
    float lastFov;
    void FUN_001c1f30(int a, float fov, float aspect, int d, int e);
};

void CameraState::FUN_001c1f30(int a, float fov, float aspect, int d, int e)
{
    camera->vfunc_21(a);
    camera->vfunc_5(fov, aspect);
    camera->vfunc_7(d);
    camera->vfunc_9(e);
    if (lastFov != fov) {
        double t = tan(fov * 0.5f) * DAT_004c5114;
        float tf = (float)t;
        halfX = (float)atan(t);
        halfY = (float)atan(tf / (DAT_0052c2a4->vfunc_16() * aspect));
        lastFov = fov;
    }
    Plane_1c1f30 tmp;
    camera->vfunc_12(1, &tmp);
    left = tmp;
    camera->vfunc_12(2, &tmp);
    right = tmp;
    camera->vfunc_12(8, &tmp);
    top = tmp;
    camera->vfunc_12(4, &tmp);
    bottom = tmp;
    camera->vfunc_12(0x10, &tmp);
    nearP = tmp;
    camera->vfunc_12(0x20, &tmp);
    farP = tmp;
}
