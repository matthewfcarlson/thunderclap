// Screen-space scale of a point: projects the point through the view, then writes
// (x, y) scale factors derived from the field of view and aspect ratio, and the depth.
struct Vec3 { float x, y, z; };
struct Matrix { float m[16]; };

struct Vec3Ops : Vec3 {
    void FUN_0022d240(const Vec3 *in, const Matrix *matrix);
};

class Display {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual float GetAspect();      // slot 16
};

union PosArg { const Vec3 *p; float f; };
struct Out { float x, y; int z; };

extern Display *DAT_0052c2a4;
extern "C" double tan(double);

class View {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void GetFov(float *a, float *b);    // slot 6
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12();
    virtual Matrix *GetMatrix();                // slot 13

    void FUN_00292cc0(PosArg pos, Out *out);
};

void View::FUN_00292cc0(PosArg pos, Out *out)
{
    struct Frame {
        float b;
        float a;
        Vec3Ops v;
    } fr;
    fr.v.FUN_0022d240(pos.p, GetMatrix());
    if (fr.v.z != 0.0f) {
        pos.f = 1.0f / fr.v.z;      // the argument slot is reused for 1/z
        GetFov(&fr.a, &fr.b);
        float aspect = DAT_0052c2a4->GetAspect() * fr.b;
        out->z = *(int *)&fr.v.z;
        float cot = 1.0f / (float)tan(fr.a * 0.5f);
        out->x = (float)(fr.v.x * cot * pos.f * 0.5f);
        out->y = (float)((cot * aspect) * fr.v.y * pos.f * 0.5f);
    }
}
