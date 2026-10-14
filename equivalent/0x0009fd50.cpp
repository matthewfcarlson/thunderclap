// STATUS: equivalent (tools/equiv.py level 3: 12018 inputs, branch coverage 7/8, incomplete)
// FUN_0009fd50 @ 0x0009fd50
extern "C" double sin(double);
extern "C" double cos(double);

struct V3_9fd50 {
    float x, y, z;
    float FUN_0022d110();
};

float __cdecl FUN_00018a20(float x);

V3_9fd50 *FUN_0009fd50(V3_9fd50 *out, V3_9fd50 *a, V3_9fd50 *b, float t)
{
    float dot = a->x * b->x + b->z * a->z;
    dot = dot + b->y * a->y;
    if (!(dot >= -1.0f))
        dot = -1.0f;
    else if (!(dot <= 1.0f))
        dot = 1.0f;

    float gap = dot - 1.0f;
    if (gap < 0.0f)
        gap = -gap;

    if (gap <= 1e-05f) {
        volatile float tx = (b->x - a->x) * t;
        volatile float ty = (b->y - a->y) * t;
        volatile float dz = b->z - a->z;
        float rz = dz * t + a->z;
        float ry = ty + a->y;
        float rx = tx + a->x;
        out->x = rx;
        out->y = ry;
        out->z = rz;
        return out;
    }

    float py = dot * a->y;
    float pz = dot * a->z;
    V3_9fd50 perp;
    perp.x = b->x - dot * a->x;
    perp.y = b->y - py;
    perp.z = b->z - pz;
    perp.FUN_0022d110();

    double theta = FUN_00018a20(dot) * t;
    double s = sin(theta);
    double c = cos(theta);
    float sx = (float)(perp.x * s);
    float sy = (float)(perp.y * s);
    double sz = perp.z * s;
    float cy = (float)(c * a->y);
    float cz = (float)(c * a->z);
    out->x = (float)(c * a->x + sx);
    out->y = cy + sy;
    out->z = (float)(cz + sz);
    return out;
}
