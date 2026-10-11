// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 9/10, incomplete)
// FUN_0009fbd0 @ 0x0009fbd0
extern "C" double exp(double);

struct Vec3 { float x, y, z; };

Vec3* FUN_0009fbd0(Vec3* out, Vec3* a, Vec3* b, Vec3* c, float tau, float dt)
{
    volatile float k = 1.0f;
    if (dt != 0.0f)
        k = (float)(1.0 - exp(-(double)(tau / dt)));
    double m = 0.0;
    if (tau != 0.0f)
        m = 1.0 - (double)k / tau * dt;
    double px = ((double)b->x - a->x) * k + a->x;
    double py = ((double)b->y - a->y) * k + a->y;
    volatile float pz = (float)(((double)b->z - a->z) * k + a->z);
    double dx = (double)c->x - b->x;
    volatile float dy = c->y - b->y;
    volatile float dz = c->z - b->z;
    volatile float ox = (float)(dx * m + px);
    volatile float oy = (float)(dy * m + py);
    volatile float oz = (float)(dz * m + pz);
    float ax = ox < 0.0f ? -ox : ox;
    float ay = oy < 0.0f ? -oy : oy;
    float az = oz < 0.0f ? -oz : oz;
    if (ax <= 1e-05f && ay <= 1e-05f && az <= 1e-05f) {
        ox = 0.0f;
        oy = 0.0f;
        oz = 0.0f;
    }
    out->x = ox;
    out->y = oy;
    out->z = oz;
    return out;
}
