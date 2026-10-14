// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 19/22, incomplete)
// pure3d::d3dContext::vfunc_109 @ 0x00323ee0
// volatile locals (nf, w2) force the float-rounded memory temporaries the original uses; 0.0f - (lo - hi) reproduces its constant-load order.
struct Matrix {
    float m[16];
};
namespace D3D8 {
void __stdcall D3DDevice_SetTransform(int, const Matrix*);
}
extern "C" double __cdecl tan(double);
extern void __fastcall FUN_0022b980(Matrix*);
class Viewport_323ee0 {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual int GetHeight();
    virtual int GetWidth();
};
struct ViewInfo {
    char pad0[0x10];
    int mode;
    float x0, y0, x1, y1;
    float nearZ, farZ, fov, aspect;
};
class Ctx_323ee0 {
  public:
    void FUN_00323ee0();
    void FUN_00321520(float x, float y, float w, float h);
    char pad0[0x48];
    ViewInfo* view;
    char pad4c[0x154 - 0x4c];
    Viewport_323ee0* viewport;
};
void Ctx_323ee0::FUN_00323ee0() {
    ViewInfo* k0 = view;
    Matrix mat;
    FUN_0022b980(&mat);
    float W = (float)viewport->GetWidth();
    float H = (float)viewport->GetHeight();
    ViewInfo* k = view;
    volatile float nf[2];
    switch (k->mode) {
    case 0: {
        nf[0] = k0->nearZ;
        nf[1] = k0->farZ;
        float A = (float)tan(view->fov * 0.5) * view->nearZ;
        float X = A / view->aspect;
        float v20 = (k->x0 + k->x0) / (k->x1 - k->x0) + 1.0f;
        if (v20 > 1.0f)
            v20 = 1.0f;
        float v1c = 1.0f - ((k->x1 - 1.0f) * 2.0f) / (k->x1 - k->x0);
        if (v1c > 1.0f)
            v1c = 1.0f;
        float va = ((k->y1 - 1.0f) * 2.0f) / (k->y0 - k->y1) + 1.0f;
        if (va > 1.0f)
            va = 1.0f;
        float vb = 1.0f - (k->y0 + k->y0) / (k->y0 - k->y1);
        if (vb > 1.0f)
            vb = 1.0f;
        float right = v1c * A;
        float left = -(v20 * A);
        float bottom = vb * X;
        float top = -(X * va);
        float Q = nf[1] / (nf[1] - nf[0]);
        volatile float w2 = bottom - top;
        mat.m[0] = (nf[0] + nf[0]) / (right - left);
        mat.m[1] = 0;
        mat.m[2] = 0;
        mat.m[3] = 0;
        mat.m[4] = 0;
        mat.m[5] = (nf[0] + nf[0]) / w2;
        mat.m[6] = 0;
        mat.m[7] = 0;
        mat.m[8] = -((left + right) / (right - left));
        mat.m[9] = -((top + bottom) / w2);
        mat.m[10] = Q;
        mat.m[11] = 1.0f;
        mat.m[12] = 0;
        mat.m[13] = 0;
        mat.m[14] = -(Q * nf[0]);
        mat.m[15] = 0;
        if (k->x0 < 0.0f)
            k->x0 = 0.0f;
        if (k->x1 > 1.0f)
            k->x1 = 1.0f;
        if (k->y1 > 1.0f)
            k->y1 = 1.0f;
        if (k->y0 < 0.0f)
            k->y0 = 0.0f;
        FUN_00321520(W * k->x0, H * k->y0, (k->x1 - k->x0) * W, (k->y1 - k->y0) * H);
        break;
    }
    case 1: {
        nf[0] = k0->nearZ;
        nf[1] = k0->farZ;
        mat.m[0] = 2.0f;
        float s = 1.0f / k0->aspect;
        mat.m[5] = 2.0f / (0.0f - ((-0.5f * s) - (0.5f * s)));
        float r = 1.0f / (nf[1] - nf[0]);
        mat.m[10] = r;
        mat.m[14] = -(r * nf[0]);
        FUN_00321520(W * k->x0, H * k->y0, (k->x1 - k->x0) * W, (k->y1 - k->y0) * H);
        break;
    }
    case 2: {
        nf[0] = k0->nearZ;
        nf[1] = k0->farZ;
        mat.m[12] = -1.0f;
        mat.m[0] = 2.0f / ((W - 0.5f) - (-0.5f));
        mat.m[13] = 1.0f;
        mat.m[5] = 2.0f / (-0.5f - (H - 0.5f));
        float r = 1.0f / (nf[1] - nf[0]);
        mat.m[10] = r;
        mat.m[14] = -(r * nf[0]);
        FUN_00321520(0.0f, 0.0f, W, H);
        break;
    }
    }
    D3D8::D3DDevice_SetTransform(1, &mat);
}
