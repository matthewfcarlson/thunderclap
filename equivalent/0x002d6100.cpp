// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// pure3d::SpriteParticleEmitter::vfunc_12 @ 0x002d6100
struct Mat4 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022cdb0();
    void FUN_00098380(Mat4 *other);
};

struct Quat {
    float x, y, z, w;
    void FUN_0022b370(Mat4 *m);
    void FUN_0022b650(Mat4 *m);
    void FUN_0022b750(Quat *a, Quat *b, float t);
};

class SpriteParticleEmitter {
public:
    virtual void v0();
    char pad04[0xb0 - 4];
    Mat4 xform;              // 0xb0
    char padf0[0x140 - 0xf0];
    Mat4 *outMatrix;         // 0x140
    float scale;             // 0x144
    float blend;             // 0x148
    unsigned int count;      // 0x14c
    float accum;             // 0x150
    float rate;              // 0x154

    void FUN_002d5ec0(float a);
    void FUN_002d5f20(float a, float b, Mat4 *m);
    void FUN_002d5fe0(float b);
    void FUN_002d6100(float a, float b);
};

void SpriteParticleEmitter::FUN_002d6100(float a, float b)
{
    if (!(b > 0.0f))
        return;

    Mat4 start = xform;
    FUN_002d5ec0(a);
    if (a - b == 0.0f)
        start = xform;
    float acc = b * rate + accum;
    accum = acc;
    FUN_002d5f20(a, b, &start);

    if (count != 0 && outMatrix != 0) {
        outMatrix->FUN_0022b980();
        if (blend > 0.0f) {
            Mat4 mid;
            Quat qs;
            Quat qe;
            Quat qr;
            mid.FUN_0022b980();
            qs.FUN_0022b370(&start);
            qe.FUN_0022b370(&xform);
            qr.FUN_0022b750(&qs, &qe, blend);
            qr.FUN_0022b650(&mid);
            Mat4 *om = outMatrix;
            *om = start;
            om->FUN_0022cdb0();
            outMatrix->FUN_00098380(&mid);
        }
        if (scale > 0.0f) {
            float vx = xform.m[12];
            float vy = xform.m[13];
            float vz = xform.m[14];
            double dx = (double)vx - (double)start.m[12];
            double dy = (double)vy - (double)start.m[13];
            volatile float dz = (float)((double)vz - (double)start.m[14]);
            float s = scale;
            float *dst = &outMatrix->m[12];
            dst[0] = (float)(s * dx);
            dst[1] = (float)(dy * s);
            dst[2] = dz * s;
        }
    }
    FUN_002d5fe0(b);
}
