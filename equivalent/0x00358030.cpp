// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_00358030 @ 0x00358030
extern "C" double sqrt(double);
extern const float DAT_003f32dc;

struct V3 {
    float x, y, z;
    void FUN_0022d180();
};

char FUN_0022d550(V3 *s, V3 *dir, V3 *a, V3 *b, float *outA, float *outB);
char FUN_00357be0(V3 *s, V3 *dir, V3 *a, V3 *b, float *outA, float *outB);

// Local frame laid out like the original's 0x94-byte frame: the callees see the neighbours of pr[],
// and the per-edge lengths and unit directions are read back even when their edge was skipped.
struct Frame {
    volatile float inv;
    float rx;
    float qzp;
    float rz;
    float pr[6];      // (ray t, edge t) for each of the three edges
    float t38, t3c, t40;
    V3 dn;
    V3 target;
    float dist[3];
    float qx;
    float rzp;
    float t70;
    float len[3];
    V3 n[3];
};

// Closest approach of a ray (S, D) to the three edges of a triangle; reports the nearest edge.
void FUN_00358030(V3 *S, V3 *D, char useSegment, V3 *P1, V3 *P0, V3 *P2,
                  float *outRay, V3 *outPoint, V3 *outDir, float *outLen, float *outEdgeT,
                  char doEdge0, char doEdge1, char doEdge2)
{
    Frame f;
    f.dn = *D;
    f.target.x = S->x + D->x;
    f.target.y = S->y + D->y;
    f.target.z = S->z + D->z;
    f.dn.FUN_0022d180();
    for (int i = 0; i < 6; i++)
        f.pr[i] = 3.4028235e38f;
    f.dist[0] = 3.4028235e38f;
    f.dist[1] = 3.4028235e38f;
    f.dist[2] = 3.4028235e38f;

    if (doEdge0) {
        float dx = P1->x - P0->x;
        float dy = P1->y - P0->y;
        f.t40 = P1->z - P0->z;
        f.len[0] = (float)sqrt(dx * dx + f.t40 * f.t40 + dy * dy);
        f.inv = DAT_003f32dc / f.len[0];
        f.n[0].x = dx * f.inv;
        f.n[0].y = dy * f.inv;
        f.n[0].z = f.t40 * f.inv;
        if (useSegment)
            FUN_00357be0(S, &f.target, P0, P1, &f.pr[0], &f.pr[1]);
        else
            FUN_0022d550(S, &f.dn, P0, P1, &f.pr[0], &f.pr[1]);
        f.qzp = f.n[0].z * f.pr[1];
        f.qx = f.n[0].x * f.pr[1] + P0->x;
        f.t40 = f.dn.z * f.pr[0];
        f.rx = f.dn.x * f.pr[0] + S->x;
        f.rz = f.t40 + S->z;
        f.t38 = f.rx - f.qx;
        f.t3c = (f.dn.y * f.pr[0] + S->y) - (f.n[0].y * f.pr[1] + P0->y);
        float dz = f.rz - (f.qzp + P0->z);
        f.dist[0] = (float)sqrt(f.t38 * f.t38 + dz * dz + f.t3c * f.t3c);
    }
    if (doEdge1) {
        float dx = P0->x - P2->x;
        float dy = P0->y - P2->y;
        f.rz = P0->z - P2->z;
        f.len[1] = (float)sqrt(dx * dx + f.rz * f.rz + dy * dy);
        f.inv = DAT_003f32dc / f.len[1];
        f.n[1].x = dx * f.inv;
        f.n[1].y = dy * f.inv;
        f.n[1].z = f.rz * f.inv;
        if (useSegment)
            FUN_00357be0(S, &f.target, P2, P0, &f.pr[2], &f.pr[3]);
        else
            FUN_0022d550(S, &f.dn, P2, P0, &f.pr[2], &f.pr[3]);
        f.qzp = f.n[1].z * f.pr[3];
        f.qx = f.n[1].x * f.pr[3] + P2->x;
        f.t70 = f.dn.z * f.pr[2];
        f.rx = f.dn.x * f.pr[2] + S->x;
        f.rz = f.t70 + S->z;
        f.t38 = f.rx - f.qx;
        f.t3c = (f.dn.y * f.pr[2] + S->y) - (f.n[1].y * f.pr[3] + P2->y);
        float dz = f.rz - (f.qzp + P2->z);
        f.dist[1] = (float)sqrt(f.t38 * f.t38 + dz * dz + f.t3c * f.t3c);
    }
    if (doEdge2) {
        float dx = P2->x - P1->x;
        float dy = P2->y - P1->y;
        f.rz = P2->z - P1->z;
        f.len[2] = (float)sqrt(dx * dx + f.rz * f.rz + dy * dy);
        f.inv = DAT_003f32dc / f.len[2];
        f.n[2].x = dx * f.inv;
        f.n[2].y = dy * f.inv;
        f.n[2].z = f.rz * f.inv;
        if (useSegment)
            FUN_00357be0(S, &f.target, P1, P2, &f.pr[4], &f.pr[5]);
        else
            FUN_0022d550(S, &f.dn, P1, P2, &f.pr[4], &f.pr[5]);
        f.qzp = f.n[2].z * f.pr[5];
        f.qx = f.n[2].x * f.pr[5] + P1->x;
        f.t70 = f.dn.z * f.pr[4];
        f.rx = f.dn.x * f.pr[4] + S->x;
        f.rz = f.t70 + S->z;
        f.t38 = f.rx - f.qx;
        f.t3c = (f.dn.y * f.pr[4] + S->y) - (f.n[2].y * f.pr[5] + P1->y);
        float dz = f.rz - (f.qzp + P1->z);
        f.dist[2] = (float)sqrt(dz * dz + f.t3c * f.t3c + f.t38 * f.t38);
    }
    if (f.dist[0] <= f.dist[1] && f.dist[0] <= f.dist[2]) {
        *outRay = f.pr[0];
        *outEdgeT = f.pr[1];
        *outPoint = *P0;
        *outDir = f.n[0];
        *outLen = f.len[0];
    } else if (f.dist[1] <= f.dist[2]) {
        *outRay = f.pr[2];
        *outEdgeT = f.pr[3];
        *outPoint = *P2;
        *outDir = f.n[1];
        *outLen = f.len[1];
    } else {
        *outRay = f.pr[4];
        *outEdgeT = f.pr[5];
        *outPoint = *P1;
        *outDir = f.n[2];
        *outLen = f.len[2];
    }
}
