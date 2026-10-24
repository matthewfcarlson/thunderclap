// STATUS: equivalent (tools/equiv.py level 3: 3286 inputs, branch coverage 20/20)
// FUN_00358b10 @ 0x00358b10
// FUN_00358b10: sweep a capsule (centre c, unit axis `axis`, half length halfLen, radius) against one
// polygon plane (point planePt, normal n; a6/a7 select the polygon) and report the contact:
// outDist (distance), outPoint (point on the plane) and outNormal (a copy of n). 11 stack args, cdecl, bool result.
//
// Floats the original stores to its frame are rounded to 24 bits (hulk_fslot); values it combines on the
// x87 stack stay unrounded (double locals and inline expressions). The result vectors are copied as raw
// 32-bit words, as the original does, so NaN payloads survive.
extern "C" double sqrt(double);

#if defined(_MSC_VER) && !defined(__clang__)
typedef volatile float hulk_fslot; // forces the store-and-reload MSVC 7.1 would otherwise skip
#else
typedef float hulk_fslot;
#endif

struct V3_358b10 {
    float x, y, z;
    void FUN_000111b0(const V3_358b10 *a, const V3_358b10 *b); // this = a x b
    void FUN_0022d180();                                       // normalise
    float FUN_00018990();                                      // length
};

bool FUN_00358630(float *p, float *dir, float r, float t, int flag, float d, float *n, float *out);
bool FUN_00357960(float *a, float *dir, float t2, float *p5, int a6, int a7, float *n, float *o9, float *o10, float *o11);
void FUN_00358030(float *a, float *dir, int flag, float *p5, int a6, int a7, float *o8c, float *o20, float *o44, float *o4, float *o64, int f1, int f2, int f3);
void FUN_0022de70(float *a, float *b, float *p5, float *p8, float *o50, float *o8);
bool FUN_003577c0(float *out, float *p5, int a6, int a7, float *p8);
float *FUN_00083e00(float *out, float *dir, float t);

static void CopyBits(float *dst, const volatile float *src)
{
    *(unsigned int *)dst = *(const volatile unsigned int *)src;
}

static float AbsBits(float v)
{
    unsigned int bits = *(unsigned int *)&v & 0x7fffffff;
    return *(float *)&bits;
}

static void CopyBits3(float *dst, const float *src)
{
    CopyBits(dst + 0, src + 0);
    CopyBits(dst + 1, src + 1);
    CopyBits(dst + 2, src + 2);
}

// The original's stack frame, in slot order: the callees' out-parameters and the vectors passed to them live
// here, and the checker's stubs write through those pointers, so the layout is part of the behaviour.
// A second copy of p1 sits in q1 until q1 is recomputed.
struct Frame_358b10 {
    hulk_fslot t;          // position along the axis
    hulk_fslot p1[3];
    hulk_fslot q1[3];
    hulk_fslot d[3];       // axis x n, later the normalised chord direction
    hulk_fslot u;          // scale of toAxis
    hulk_fslot planeHit;   // distance the plane test reports
    hulk_fslot start[3];   // c - halfLen * axis
    hulk_fslot contact[3]; // contact point on the plane
    hulk_fslot toAxis[3];  // direction from the polygon point towards the axis; its z is first axis offset z
    hulk_fslot q[3];       // (n x axis) x axis
    hulk_fslot nearEnd[3]; // capsule end nearer to the plane
    hulk_fslot onPoly[3];  // closest point on the polygon
    hulk_fslot tmp[3];     // scratch vector returned by FUN_00083e00
    hulk_fslot side;
    hulk_fslot unusedOut;
};

#define FP(v) ((float *)(v))

bool FUN_00358b10(float *c, float *axis, float radius, float halfLen, float *planePt, int a6, int a7,
                  float *n, float *outDist, float *outPoint, float *outNormal)
{
    Frame_358b10 fr;

    // Plane offset: -(n . planePt).
    hulk_fslot planeD = -(((n[2] * planePt[2]) + (n[1] * planePt[1])) + (n[0] * planePt[0]));
    if (!FUN_00358630(c, axis, radius, halfLen, 1, planeD, n, FP(&fr.planeHit)))
        return false;

    // The capsule's far end: start = c - halfLen * axis.
    fr.toAxis[2] = halfLen * axis[2];
    fr.start[0] = c[0] - (halfLen * axis[0]);
    fr.start[1] = c[1] - (halfLen * axis[1]);
    fr.start[2] = c[2] - fr.toAxis[2];
    hulk_fslot fullLen = halfLen + halfLen;

    if (FUN_00357960(FP(fr.start), axis, fullLen, planePt, a6, a7, n, outDist, outPoint, outNormal)) {
        CopyBits(&outDist[0], &fr.planeHit);
        return true;
    }

    // Closest approach of the axis segment to the polygon.
    FUN_00358030(FP(fr.start), axis, 0, planePt, a6, a7, FP(&fr.t), FP(fr.onPoly), FP(fr.toAxis),
                 FP(&fr.unusedOut), FP(&fr.u), 1, 1, 1);
    if (0.0f < fr.t && fr.t < fullLen) {
        float axisY = axis[1];
        hulk_fslot tz = fr.t * axis[2];
        hulk_fslot tx = (fr.t * axis[0]) + fr.start[0];
        hulk_fslot nz = fr.toAxis[2] * fr.u;
        hulk_fslot px = fr.onPoly[0] + (fr.toAxis[0] * fr.u);
        CopyBits(&outPoint[0], &px);
        hulk_fslot pz = fr.onPoly[2] + nz;
        outPoint[1] = fr.onPoly[1] + (fr.toAxis[1] * fr.u);
        outPoint[2] = fr.onPoly[2] + nz;
        hulk_fslot dx = tx - px;
        hulk_fslot dy = ((fr.t * axisY) + fr.start[1]) - (fr.onPoly[1] + (fr.toAxis[1] * fr.u));
        double dist = sqrt(((dx * dx) + (((tz + fr.start[2]) - pz) * ((tz + fr.start[2]) - pz))) + (dy * dy));
        outDist[0] = (float)dist;
        if (dist < radius) {
            CopyBits3(outNormal, n);
            CopyBits(&outDist[0], &fr.planeHit);
            return true;
        }
    }

    // Pick whichever capsule end is closer to the plane.
    hulk_fslot endZ = halfLen * axis[2];
    hulk_fslot endX = (halfLen * axis[0]) + c[0];
    hulk_fslot endZ2 = endZ + c[2];
    hulk_fslot startSide = (((fr.start[2] * n[2]) + (fr.start[1] * n[1])) + (fr.start[0] * n[0])) -
                           (((n[2] * planePt[2]) + (n[1] * planePt[1])) + (n[0] * planePt[0]));
    hulk_fslot startDist = AbsBits(startSide);
    hulk_fslot endSide = (((endZ2 * n[2]) + (((halfLen * axis[1]) + c[1]) * n[1])) + (endX * n[0])) -
                         (((n[2] * planePt[2]) + (n[1] * planePt[1])) + (n[0] * planePt[0]));
    hulk_fslot endDist = AbsBits(endSide);
    if (startDist < endDist) {
        fr.nearEnd[0] = fr.start[0];
        fr.nearEnd[1] = fr.start[1];
        fr.nearEnd[2] = fr.start[2];
    } else {
        fr.nearEnd[0] = endX;
        fr.nearEnd[1] = (halfLen * axis[1]) + c[1];
        fr.nearEnd[2] = endZ2;
    }

    // q = (n x axis) x axis: the part of n perpendicular to the axis.
    hulk_fslot cx = (n[1] * axis[2]) - (n[2] * axis[1]);
    hulk_fslot cz = (n[0] * axis[1]) - (n[1] * axis[0]);
    fr.q[0] = (((n[2] * axis[0]) - (n[0] * axis[2])) * axis[2]) - (cz * axis[1]);
    fr.q[1] = (((n[0] * axis[1]) - (n[1] * axis[0])) * axis[0]) - (cx * axis[2]);
    fr.q[2] = (cx * axis[1]) - (((n[2] * axis[0]) - (n[0] * axis[2])) * axis[0]);

    FUN_0022de70(FP(fr.nearEnd), FP(fr.q), planePt, n, FP(fr.contact), FP(&fr.side));
    hulk_fslot sideDist = AbsBits(fr.side);
    if (sideDist > radius)
        return false;
    if (FUN_003577c0(FP(fr.contact), planePt, a6, a7, n)) {
        CopyBits3(outPoint, FP(fr.contact));
        CopyBits(&outDist[0], &fr.planeHit);
        CopyBits3(outNormal, n);
        return true;
    }

    // Intersect the axis line with the capsule radius around the contact point: a quadratic in the
    // distance along d = axis x n.
    ((V3_358b10 *)FP(fr.d))->FUN_000111b0((V3_358b10 *)axis, (V3_358b10 *)n);
    hulk_fslot dd = ((fr.d[2] * fr.d[2]) + (fr.d[1] * fr.d[1])) + (fr.d[0] * fr.d[0]);
    double halfB = ((fr.d[2] * (fr.contact[2] - fr.nearEnd[2])) + ((fr.contact[1] - fr.nearEnd[1]) * fr.d[1])) +
                   ((fr.contact[0] - fr.nearEnd[0]) * fr.d[0]);
    hulk_fslot twoB = halfB + halfB;
    double gap = (((fr.contact[2] - fr.nearEnd[2]) * (fr.contact[2] - fr.nearEnd[2])) +
                  ((fr.contact[1] - fr.nearEnd[1]) * (fr.contact[1] - fr.nearEnd[1]))) +
                 ((fr.contact[0] - fr.nearEnd[0]) * (fr.contact[0] - fr.nearEnd[0]));
    double disc = ((halfB + halfB) * twoB) - (((gap - (radius * radius)) * dd) * 4.0f);
    if (!(1e-5f < disc))
        return false;
    hulk_fslot root = sqrt(disc);
    hulk_fslot twoA = dd + dd;

    hulk_fslot step1 = (root - twoB) / twoA;
    float *r1 = FUN_00083e00(FP(fr.tmp), FP(fr.d), step1);
    fr.q1[0] = fr.contact[0] + r1[0];
    fr.q1[1] = fr.contact[1] + r1[1];
    fr.q1[2] = fr.contact[2] + r1[2];
    fr.p1[0] = fr.contact[0] + r1[0];
    fr.p1[1] = fr.contact[1] + r1[1];
    fr.p1[2] = fr.q1[2];
    hulk_fslot step2 = ((-twoB) - root) / twoA;
    r1 = FUN_00083e00(FP(fr.tmp), FP(fr.d), step2);
    fr.tmp[2] = fr.contact[2] + r1[2];
    fr.d[0] = (fr.contact[0] + r1[0]) - fr.q1[0];
    fr.d[1] = (fr.contact[1] + r1[1]) - fr.q1[1];
    fr.d[2] = fr.tmp[2] - fr.q1[2];
    ((V3_358b10 *)FP(fr.d))->FUN_0022d180();

    // Nearest approach of the new axis segment to the polygon.
    FUN_00358030(FP(fr.p1), FP(fr.d), 1, planePt, a6, a7, FP(&fr.t), FP(fr.onPoly), FP(fr.toAxis),
                 FP(&fr.unusedOut), FP(&fr.u), 1, 1, 1);
    r1 = FUN_00083e00(FP(fr.tmp), FP(fr.d), fr.t);
    fr.q1[0] = fr.p1[0] + r1[0];
    fr.q1[1] = fr.p1[1] + r1[1];
    fr.q1[2] = fr.p1[2] + r1[2];
    r1 = FUN_00083e00(FP(fr.tmp), FP(fr.toAxis), fr.u);
    hulk_fslot ox = r1[0];
    hulk_fslot oy = r1[1];
    hulk_fslot oz = r1[2];
    fr.tmp[2] = fr.onPoly[2] + oz;
    outPoint[0] = fr.onPoly[0] + ox;
    outPoint[1] = fr.onPoly[1] + oy;
    outPoint[2] = fr.onPoly[2] + oz;
    fr.toAxis[0] = fr.q1[0] - (fr.onPoly[0] + ox);
    fr.toAxis[1] = fr.q1[1] - (fr.onPoly[1] + oy);
    fr.toAxis[2] = fr.q1[2] - fr.tmp[2];
    double len = ((V3_358b10 *)FP(fr.toAxis))->FUN_00018990();
    outDist[0] = (float)len;
    if (!(len < 0.1f))
        return false;
    CopyBits3(outNormal, n);
    CopyBits(&outDist[0], &fr.planeHit);
    return true;
}
