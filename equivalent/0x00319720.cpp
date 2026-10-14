// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// physics::SimpleFilter3D::vfunc_1 @ 0x00319720
struct V3_319720 {
    float x, y, z;
};

class SimpleFilter3D {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(const V3_319720 *in, float dt);
    virtual void vfunc_2();
    float rate[3];     // 0x04
    float alpha[3];    // 0x10
    float out[3];      // 0x1c
    float lastDt;      // 0x28
};

void SimpleFilter3D::vfunc_1(const V3_319720 *in, float dt)
{
    if (dt != lastDt) {
        alpha[0] = dt * rate[0];
        alpha[1] = dt * rate[1];
        alpha[2] = dt * rate[2];
        for (int i = 0; i < 3; i++) {
            if (alpha[i] <= 0.0f)
                alpha[i] = 0.0f;
            else if (alpha[i] > 0.999999f)
                alpha[i] = 0.999999f;
        }
        if (lastDt == 0.0f) {
            float x = in->x;
            float y = in->y;
            float z = in->z;
            volatile float sz = z * alpha[2];
            volatile float *o = out;
            o[0] = o[0] * 1.5f;
            o[1] = o[1] * 1.5f;
            o[2] = o[2] * 1.5f;
            o[0] = o[0] - x * alpha[0];
            o[1] = o[1] - y * alpha[1];
            o[2] = o[2] - sz;
            o[0] = o[0] / (1.0f - alpha[0]);
            o[1] = o[1] / (1.0f - alpha[1]);
            o[2] = o[2] / (1.0f - alpha[2]);
        }
        lastDt = dt;
    }
    out[0] = (in->x - out[0]) * alpha[0] + out[0];
    out[1] = (in->y - out[1]) * alpha[1] + out[1];
    out[2] = (in->z - out[2]) * alpha[2] + out[2];
}
