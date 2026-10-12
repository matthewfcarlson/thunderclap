// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 50/50)
// FUN_0022d730 @ 0x0022d730
struct V3 {
    float x, y, z;
};

bool FUN_0022d730(const V3 *p1, const V3 *d1, float smax, const V3 *p2, const V3 *d2,
                  float tmax, float *sOut, float *tOut)
{
    double x0 = p1->x - p2->x;
    double y0 = p1->y - p2->y;
    double z0 = p1->z - p2->z;
    float b = d1->x * d2->x + d1->z * d2->z + d1->y * d2->y;
    float c = z0 * d1->z + y0 * d1->y + x0 * d1->x;
    float f = (x0 * d2->x + z0 * d2->z) + y0 * d2->y;
    float denom = 1.0f - b * b;

    if (denom >= 0.00001f) {
        double inv = 1.0 / denom;
        *sOut = (f * b - c) * inv;
        float t = (f - c * b) * inv;
        *tOut = t;
        volatile bool inRange = (0.0f <= *sOut && *sOut <= smax && 0.0f <= t && t <= tmax);
        if (inRange)
            return true;
    }

    bool sOutside = (*sOut < 0.0f) || (*sOut > smax);
    bool tOutside = (*tOut < 0.0f) || (*tOut > tmax);

    if (!sOutside) {
        float tt = (*tOut < 0.0f) ? 0.0f : tmax;
        *tOut = tt;
        double sp = tt * b - c;
        *sOut = (float)sp;
        if (sp < 0.0)
            *sOut = 0.0f;
        else if (sp > smax)
            *sOut = smax;
    } else if (!tOutside) {
        float sc = (*sOut < 0.0f) ? 0.0f : smax;
        *sOut = sc;
        double tp = sc * b + f;
        *tOut = (float)tp;
        if (tp < 0.0)
            *tOut = 0.0f;
        else if (tp > tmax)
            *tOut = tmax;
    } else {
        float sc = (*sOut < 0.0f) ? 0.0f : smax;
        double uu = sc * b + f;
        float tc = (float)uu;
        if (uu < 0.0)
            tc = 0.0f;
        else if (tc > tmax)
            tc = tmax;
        float ts = (*tOut < 0.0f) ? 0.0f : tmax;
        double sv = ts * b - c;
        if (sv < 0.0)
            sv = 0.0f;
        else if (sv > smax)
            sv = smax;

        volatile float qx = tc * d2->x + p2->x;
        double qy = tc * d2->y + p2->y;
        volatile float qz0 = tc * d2->z;
        double qz = qz0 + p2->z;
        volatile float scz0 = sc * d1->z;
        volatile float px = sc * d1->x + p1->x;
        double py = sc * d1->y + p1->y;
        volatile float pz = scz0 + p1->z;
        volatile float dx1 = px - qx;
        volatile float dy1 = py - qy;
        double dz1 = pz - qz;

        volatile float q2x = ts * d2->x + p2->x;
        double q2y = ts * d2->y + p2->y;
        volatile float q2z0 = ts * d2->z;
        double q2z = q2z0 + p2->z;
        volatile float svz0 = sv * d1->z;
        volatile float p2x = sv * d1->x + p1->x;
        volatile float p2y = sv * d1->y + p1->y;
        double p2z = svz0 + p1->z;
        volatile float dx2 = p2x - q2x;
        volatile float dy2 = p2y - q2y;
        double dz2 = p2z - q2z;

        double n1 = dz1 * dz1 + dy1 * dy1 + dx1 * dx1;
        double n2 = dz2 * dz2 + dy2 * dy2 + dx2 * dx2;
        if (n1 < n2) {
            *sOut = sc;
            *tOut = tc;
        } else {
            *sOut = (float)sv;
            *tOut = ts;
        }
    }
    return denom >= 0.00001f;
}
