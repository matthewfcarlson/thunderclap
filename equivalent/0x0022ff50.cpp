// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_0022ff50 @ 0x0022ff50
extern "C" double sqrt(double);

struct Vec3_22ff50 { float x, y, z; };

// Distance from point p to the segment [a, b].
class Segment_22ff50 {
public:
    Vec3_22ff50 a;
    Vec3_22ff50 b;
    float FUN_0022ff50(Vec3_22ff50 *p);
};

float Segment_22ff50::FUN_0022ff50(Vec3_22ff50 *p)
{
    float dx = b.x - a.x;
    float dy = b.y - a.y;
    float dz = b.z - a.z;
    float px = p->x - a.x;
    float py = p->y - a.y;
    float pz = p->z - a.z;
    float dot = pz * dz + py * dy + px * dx;
    if (dot <= 0.0f)
        return (float)sqrt(pz * pz + py * py + px * px);
    float len2 = dz * dz + dx * dx + dy * dy;
    if (len2 <= dot) {
        float ex = p->x - b.x;
        float ey = p->y - b.y;
        float ez = p->z - b.z;
        return (float)sqrt(ez * ez + ey * ey + ex * ex);
    }
    float t = dot / len2;
    float cx = dx * t + a.x;
    volatile float sy = dy * t;
    volatile float sz = dz * t;
    float cy = sy + a.y;
    volatile float cz = sz + a.z;
    volatile float ex = p->x - cx;
    float ey = p->y - cy;
    float ez = p->z - cz;
    return (float)sqrt(ez * ez + ey * ey + ex * ex);
}
