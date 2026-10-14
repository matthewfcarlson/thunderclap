// STATUS: equivalent (tools/equiv.py level 3: 12000 inputs, branch coverage 8/8; run with --inputs 12000)
// FUN_002f04c0 @ 0x002f04c0
extern "C" double sqrt(double);

struct Vec3_2f04c0 {
    float x, y, z;
};

bool FUN_002f04c0(const Vec3_2f04c0 *c, const Vec3_2f04c0 *d, float maxDist, float radius, float *out)
{
    radius = radius * radius;

    float cc = c->x * c->x + c->y * c->y + c->z * c->z;
    if (cc <= radius) {
        *out = 0.0f;
        return true;
    }

    float b = c->x * d->x + c->y * d->y + d->z * c->z;
    if (b >= 0.0f)
        return false;
    b = -b;

    float px = b * d->x + c->x;
    float py = b * d->y + c->y;
    float pz = b * d->z + c->z;
    float q = pz * pz + px * px + py * py;
    if (!(q < radius))
        return false;

    float s = -(float)sqrt((double)(radius - q));
    float x1 = s * d->x + px;
    float y1 = s * d->y + py;
    float z1 = s * d->z + pz;

    float ex = x1 - c->x;
    float ey = y1 - c->y;
    float ez = z1 - c->z;
    float sum = ez * ez + ex * ex + ey * ey;
    if (!(sum <= maxDist * maxDist))
        return false;

    *out = (float)sqrt((double)sum);
    return true;
}
