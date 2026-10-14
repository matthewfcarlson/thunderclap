// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00357be0 @ 0x00357be0
extern "C" double sqrt(double);

struct Vec3_357be0 {
    float x, y, z;
};

struct Frame_357be0 {
    Vec3_357be0 w;
    Vec3_357be0 dir;
};

extern void __cdecl FUN_0022d730(Vec3_357be0 *a, Vec3_357be0 *dirA, float lenA, Vec3_357be0 *b, Vec3_357be0 *dirB, float lenB, int p7, int p8);

// Builds the unit direction and length of the segments p0->p1 and p2->p3 and forwards them.
// dx and dy stay unrounded on the FPU, everything the original stores is read back from memory.
void FUN_00357be0(Vec3_357be0 *p0, Vec3_357be0 *p1, Vec3_357be0 *p2, Vec3_357be0 *p3, int arg5, int arg6)
{
    Frame_357be0 frame;
    volatile Frame_357be0 *fr = &frame;
    double dx = p1->x - p0->x;
    double dy = p1->y - p0->y;
    fr->dir.z = p1->z - p0->z;
    fr->w.x = p3->x - p2->x;
    fr->w.y = p3->y - p2->y;
    fr->w.z = p3->z - p2->z;
    volatile float lenA = (float)sqrt(fr->dir.z * fr->dir.z + dy * dy + dx * dx);
    volatile float lenB = (float)sqrt(fr->w.z * fr->w.z + fr->w.y * fr->w.y + fr->w.x * fr->w.x);
    volatile float invA = 1.0f / lenA;
    fr->dir.x = (float)(dx * invA);
    fr->dir.y = (float)(dy * invA);
    fr->dir.z = fr->dir.z * invA;
    double invB = 1.0f / lenB;
    fr->w.x = (float)(fr->w.x * invB);
    fr->w.y = (float)(fr->w.y * invB);
    fr->w.z = (float)(fr->w.z * invB);
    FUN_0022d730(p0, &frame.dir, lenA, p2, &frame.w, lenB, arg5, arg6);
}
