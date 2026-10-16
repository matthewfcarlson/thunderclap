// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 19/20, incomplete)
// FUN_001c2940 @ 0x001c2940
struct Plane {
    float nx, ny, nz;
    float d;
};

struct V3 {
    float x, y, z;
};

// Intersection line of two planes: dir = a.n x b.n, point = a point on both planes with
// the dominant component of dir set to 0. Returns 1 when the planes are (nearly) parallel.
//
// The x87 runs at 53-bit precision here, so the values the original keeps on the FPU stack
// are written as doubles. Values it stores to a float slot and reloads are volatile floats
// (MSVC would otherwise drop the rounding).
int __cdecl FUN_001c2940(const Plane *a, const Plane *b, V3 *point, V3 *dir)
{
    volatile float cx = b->nz * a->ny - b->ny * a->nz;
    double cy = (double)b->nx * a->nz - (double)b->nz * a->nx;
    volatile float cz = b->ny * a->nx - b->nx * a->ny;

    volatile float ax = (cx >= 0.0f) ? cx : -cx;
    volatile float ay = (cy >= 0.0) ? (float)cy : (float)-cy;
    float az = (cz >= 0.0f) ? cz : -cz;

    if ((ay + az) + ax < 0.01f)
        return 1;

    int axis;
    if (ax > ay)
        axis = (ax > az) ? 0 : 2;
    else
        axis = (ay > az) ? 1 : 2;

    // k1 = -dot(a.n * -a.d, a.n), k2 = -dot(b.n * -b.d, b.n)
    double nA = -a->d;
    double pAx = nA * a->nx;
    double pAy = nA * a->ny;
    double pAz = nA * a->nz;
    double nB = -b->d;
    volatile float pbx = (float)(nB * b->nx);
    volatile float pby = (float)(nB * b->ny);
    volatile float pbz = (float)(nB * b->nz);
    double k1 = -((pAx * a->nx + pAz * a->nz) + pAy * a->ny);
    double k2 = -(((double)pbz * b->nz + (double)pby * b->ny) + (double)pbx * b->nx);

    volatile float px;
    volatile float py;
    double pz;
    if (axis == 0) {
        double inv = 1.0 / cx;
        px = 0.0f;
        py = (float)((k2 * a->nz - k1 * b->nz) * inv);
        pz = (k1 * b->ny - k2 * a->ny) * inv;
    } else if (axis == 1) {
        double inv = 1.0 / cy;
        py = 0.0f;
        px = (float)((k1 * b->nz - k2 * a->nz) * inv);
        pz = (k2 * a->nx - k1 * b->nx) * inv;
    } else {
        double inv = 1.0 / cz;
        px = (float)((k2 * a->ny - k1 * b->ny) * inv);
        py = (float)((k1 * b->nx - k2 * a->nx) * inv);
        pz = 0.0;
    }

    point->x = px;
    point->z = (float)pz;
    point->y = py;
    dir->x = cx;
    dir->z = cz;
    dir->y = (float)cy;
    return 0;
}
