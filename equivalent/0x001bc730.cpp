// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001bc730 @ 0x001bc730
// FUN_001bc730: send the camera orientation (rows: right, -forward-ish, up) to the renderer
struct Matrix {
    float m[16];
    void FUN_0022b980();    // identity
};

struct Camera {
    Matrix view;
};

struct CameraSet {
    Camera *FUN_001c12b0();
};

struct CameraManager_1bc730 {
    CameraSet *set;
};

struct Renderer_1bc730 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void SetOrientation(int zero, Matrix *m);
};

CameraManager_1bc730 *__cdecl FUN_001c3d90();
struct RendererHolder {
    Renderer_1bc730 *renderer;
};
extern RendererHolder *DAT_0052c2ac;

struct Frame_1bc730 {
    Matrix out;
    int pad[2];
    volatile float tmp;
    Matrix view;
};

void FUN_001bc730()
{
    Frame_1bc730 f;
    f.view = FUN_001c3d90()->set->FUN_001c12b0()->view;
    f.out.FUN_0022b980();
    float *v = f.view.m;
    float *o = f.out.m;
    ((int *)o)[0] = ((int *)v)[0];
    ((int *)o)[1] = ((int *)v)[1];
    ((int *)o)[2] = ((int *)v)[2];
    float nx = -v[8];
    float ny = -v[9];
    f.tmp = -v[10];
    o[4] = nx;
    o[5] = ny;
    ((int *)o)[6] = *(volatile int *)&f.tmp;
    ((int *)o)[8] = ((int *)v)[4];
    ((int *)o)[9] = ((int *)v)[5];
    ((int *)o)[10] = ((int *)v)[6];
    DAT_0052c2ac->renderer->SetOrientation(0, &f.out);
}
