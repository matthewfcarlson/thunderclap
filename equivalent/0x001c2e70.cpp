// STATUS: equivalent (tools/equiv.py level 3: 44 inputs, branch coverage 26/34, incomplete)
// FUN_001c2e70 @ 0x001c2e70
struct Vec3 { float x, y, z; };
struct PointList { Vec3 *begin; Vec3 *end; };
struct Plane { float a, b, c, d; };

class Hull {
public:
    unsigned int count;
    Plane planes[1];

    bool FUN_001c2e70(const PointList *pts);
};

bool Hull::FUN_001c2e70(const PointList *pts)
{
    const Vec3 *p = pts->begin;
    int n = pts->end - pts->begin;
    unsigned int total = count;
    for (unsigned int i = 0; i < total; i++) {
        const Plane *pl = &planes[i];
        bool all = true;
        int j = 0;
        for (; j + 4 <= n; j += 4) {
            const Vec3 *q = &p[j];
            all &= !((q[0].x * pl->a + q[0].z * pl->c) + q[0].y * pl->b <= -pl->d);
            all &= !((q[1].z * pl->c + q[1].x * pl->a) + q[1].y * pl->b <= -pl->d);
            all &= !((q[2].z * pl->c + q[2].y * pl->b) + q[2].x * pl->a <= -pl->d);
            all &= !((q[3].z * pl->c + q[3].y * pl->b) + q[3].x * pl->a <= -pl->d);
        }
        for (; j < n; j++) {
            const Vec3 *q = &p[j];
            all &= !((q->z * pl->c + q->y * pl->b) + q->x * pl->a <= -pl->d);
        }
        if (all)
            return false;
    }
    return true;
}
