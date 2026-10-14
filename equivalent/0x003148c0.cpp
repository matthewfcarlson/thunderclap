// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_003148c0 @ 0x003148c0
extern "C" double sqrt(double);

struct V3_3148c0 { float v[3]; };

int __cdecl FUN_00305a40(V3_3148c0 *dir, int mode);

// Solves for the point where two planes' constraints meet along the plane
// orthogonal to the dominant axis of the cross product of a3 and a4.
bool __stdcall FUN_003148c0(V3_3148c0 *a1, V3_3148c0 *a2, V3_3148c0 *a3, V3_3148c0 *a4, V3_3148c0 *result, V3_3148c0 *axisDir, bool computeAxis)
{
    if (computeAxis) {
        // all three components are computed before any is stored (the output may alias the inputs)
        double cx = a3->v[1] * a4->v[2] - a3->v[2] * a4->v[1];
        double cy = a3->v[2] * a4->v[0] - a3->v[0] * a4->v[2];
        double cz = a3->v[0] * a4->v[1] - a3->v[1] * a4->v[0];
        axisDir->v[0] = (float)cx;
        axisDir->v[1] = (float)cy;
        axisDir->v[2] = (float)cz;
    }
    float len = (float)sqrt(axisDir->v[0] * axisDir->v[0] + axisDir->v[1] * axisDir->v[1] + axisDir->v[2] * axisDir->v[2]);
    if (len < 9.99999997e-007f)
        return false;

    float d1 = -(a1->v[2] * a3->v[2] + a1->v[1] * a3->v[1] + a3->v[0] * a1->v[0]);
    float d2 = -(a2->v[2] * a4->v[2] + a2->v[1] * a4->v[1] + a2->v[0] * a4->v[0]);
    int axis = FUN_00305a40(axisDir, 1);
    int u = 0;
    int w = 1;
    if (axis == 0) {
        u = 1;
        w = 2;
    } else if (axis == 1) {
        u = 2;
        w = 0;
    }
    float t1 = a4->v[u];
    float t2 = a3->v[u];
    float pivot = axisDir->v[axis];
    result->v[axis] = 0.0f;
    result->v[u] = (a3->v[w] * d2 - a4->v[w] * d1) / pivot;
    result->v[w] = (t1 * d1 - t2 * d2) / pivot;
    return true;
}
