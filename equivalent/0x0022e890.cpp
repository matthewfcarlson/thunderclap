// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0022e890 @ 0x0022e890
// Segment::FUN_0022e890 @ 0x0022e890: evaluate the cubic segment at t (clamped to [0,1])
struct V3 {
    float x, y, z;
};

struct Matrix {
    float m[16];
};

struct Vec4 {
    float x, y, z, w;
    void FUN_002306c0(const Matrix *mat);
};

class Segment {
public:
    float m[16];
    Vec4 pos;
    void FUN_0022e890(V3 *out, float t);
};

void Segment::FUN_0022e890(V3 *out, float t)
{
    if (!(t >= 0.0f))
        t = 0.0f;
    else if (t > 1.0f)
        t = 1.0f;

    pos.x = 1.0f;
    pos.y = t;
    pos.z = t * t;
    pos.w = t * t * t;
    pos.FUN_002306c0((const Matrix *)this);

    out->x = pos.x;
    out->y = pos.y;
    out->z = pos.z;
}
