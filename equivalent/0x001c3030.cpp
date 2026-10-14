// STATUS: equivalent (tools/equiv.py level 3: 2726 inputs, branch coverage 47/50, incomplete)
// FUN_001c3030 @ 0x001c3030
struct Vec3 {
    float x, y, z;
    bool FUN_0022d2b0(Vec3 *other, float eps);
    void FUN_0022d180();
};

struct Plane {
    float nx, ny, nz;
    float d;
};

union FS {
    float f;
    unsigned int u;
};

struct PointSet {
    Vec3 points[32];
    unsigned int count;
    void FUN_001c2c20(Vec3 *p);
    Vec3 *FUN_001c2c90(Vec3 *out);
};

struct Segment {
    Vec3 p;
    Vec3 q;
    char dropped;
    char pad19[3];
};

int __cdecl FUN_001c2940(Plane *a, Plane *b, Vec3 *point, Vec3 *dir);

// A convex region bounded by up to six planes.
struct Hull {
    unsigned int count;
    Plane planes[6];
    Vec3 *FUN_001c3030(Vec3 *out);
};

// Clips every pairwise plane-intersection line against all planes, then returns the centroid of the surviving
// segment end points.
Vec3 *Hull::FUN_001c3030(Vec3 *out)
{
    struct Frame {
        Vec3 dir;                    // 0x00
        char pad0c[0x2c - 0x0c];
        Vec3 pt;                     // 0x2c
        char pad38[0x60 - 0x38];
        Segment segs[32];            // 0x60
        unsigned int segCount;       // 0x3e0
        PointSet set;                // 0x3e4
    } f;

    for (int k = 0; k < 32; k++)
        f.segs[k].dropped = 0;
    f.segCount = 0;
    f.set.count = 0;

    unsigned int n = count > 6 ? 6 : count;
    unsigned int a;
    unsigned int b;
    for (a = 0; a < n; a++) {
        for (b = a + 1; b < n; b++) {
            if (FUN_001c2940(&planes[a], &planes[b], &f.pt, &f.dir) != 0)
                continue;
            f.dir.x = f.dir.x * 10000.0f;
            f.dir.y = f.dir.y * 10000.0f;
            f.dir.z = f.dir.z * 10000.0f;
            Vec3 far1;
            far1.x = f.pt.x + f.dir.x;
            far1.y = f.pt.y + f.dir.y;
            far1.z = f.pt.z + f.dir.z;
            f.pt.x = f.pt.x - f.dir.x;
            f.pt.y = f.pt.y - f.dir.y;
            f.pt.z = f.pt.z - f.dir.z;
            if (f.segCount < 32) {
                f.segs[f.segCount].p = f.pt;
                f.segs[f.segCount].q = far1;
                f.segCount++;
            }
        }
    }

    unsigned int s;
    for (s = 0; s < f.segCount; s++) {
        Segment *seg = &f.segs[s];
        int clipped = 0;
        if (n != 0) {
            unsigned int j;
            for (j = 0; j < n; j++) {
                Plane *pl = &planes[j];
                float inP = ((seg->p.z * pl->nz + seg->p.y * pl->ny) + pl->nx * seg->p.x) <= -pl->d ? 1.0f : 0.0f;
                float inQ = ((seg->q.z * pl->nz + seg->q.y * pl->ny) + pl->nx * seg->q.x) <= -pl->d ? 1.0f : 0.0f;
                Vec3 *outer;
                if (inP == 0.0f) {
                    if (inQ == 0.0f)
                        continue;
                    outer = &seg->p;
                } else {
                    if (inQ != 0.0f)
                        continue;
                    outer = &seg->q;
                }
                Vec3 *inner = outer->FUN_0022d2b0(&seg->p, 1e-5f) ? &seg->q : &seg->p;
                f.dir.x = inner->x - outer->x;
                f.dir.y = inner->y - outer->y;
                f.dir.z = inner->z - outer->z;
                f.dir.FUN_0022d180();
                double den = (f.dir.y * pl->ny + f.dir.x * pl->nx) + f.dir.z * pl->nz;
                FS ad;
                ad.f = (float)den;
                ad.u &= 0x7fffffff;
                double num = -pl->d - ((pl->nz * outer->z + pl->ny * outer->y) + outer->x * pl->nx);
                double t = num / den;
                if (!(ad.f <= 1e-5f) && !(t < 0.0f)) {
                    clipped++;
                    float yy = (float)(f.dir.y * t);
                    float zz = (float)(f.dir.z * t);
                    outer->x = (float)(f.dir.x * t + outer->x);
                    outer->y = yy + outer->y;
                    outer->z = zz + outer->z;
                }
            }
        }
        if (clipped < 2)
            seg->dropped = 1;
    }

    for (s = 0; s < f.segCount; s++) {
        if (f.segs[s].dropped == 0) {
            f.set.FUN_001c2c20(&f.segs[s].p);
            f.set.FUN_001c2c20(&f.segs[s].q);
        }
    }
    f.set.FUN_001c2c90(out);
    return out;
}
