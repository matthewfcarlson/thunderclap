// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001acdd0 @ 0x001acdd0
struct Vec3 { float x, y, z; };
struct Mesh { Vec3 *FUN_001b56a0(int face, int corner); };

// Centroid of the three corners of a face.  The x sum is rounded to float
// before it is scaled, y stays unrounded, z rounds its first partial sum.
void __cdecl FUN_001acdd0(Vec3 *out, Mesh *mesh, int face)
{
    Vec3 r;
    Vec3 *a = mesh->FUN_001b56a0(face, 0);
    Vec3 *b = mesh->FUN_001b56a0(face, 1);
    Vec3 *c = mesh->FUN_001b56a0(face, 2);
    volatile float *px = &r.x;
    volatile float z1 = b->z + a->z;
    *px = (b->x + a->x) + c->x;
    r.y = ((b->y + a->y) + c->y) * 0.33333334f;
    r.z = (z1 + c->z) * 0.33333334f;
    *px = *px * 0.33333334f;
    *out = r;
}
