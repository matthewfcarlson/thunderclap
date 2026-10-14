// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022fec0 @ 0x0022fec0
extern "C" double sqrt(double);

struct Bounds_22fec0 {
    float min[3];
    float max[3];
    void GetCenter(struct CenterRadius *out);
};

struct CenterRadius {
    float x, y, z;
    float radius;
};

void Bounds_22fec0::GetCenter(CenterRadius *out)
{
    float dx = min[0] - max[0];
    float dy = min[1] - max[1];
    float dz = min[2] - max[2];
    float sx = min[0] + max[0];
    float sy = max[1] + min[1];
    float sz = max[2] + min[2];
    out->x = sx * 0.5f;
    out->y = sy * 0.5f;
    out->z = sz * 0.5f;
    out->radius = (float)sqrt(dz * dz + dx * dx + dy * dy);
}
