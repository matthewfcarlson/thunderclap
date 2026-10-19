// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001acdd0 @ 0x001acdd0
struct Vec3_1acdd0 { float x, y, z; };
struct Mesh_1acdd0 { Vec3_1acdd0 *FUN_001b56a0(int face, int corner); };

// Centroid of the three corners of a face.  The x sum is rounded to float
// before it is scaled, y stays unrounded, z rounds its first partial sum.
Vec3_1acdd0 * __cdecl FUN_001acdd0(Vec3_1acdd0 *out, Mesh_1acdd0 *mesh, int face)
{
    Vec3_1acdd0 r;
    Vec3_1acdd0 *a = mesh->FUN_001b56a0(face, 0);
    Vec3_1acdd0 *b = mesh->FUN_001b56a0(face, 1);
    Vec3_1acdd0 *c = mesh->FUN_001b56a0(face, 2);
    volatile float *px = &r.x;
    volatile float z1 = b->z + a->z;
    *px = (b->x + a->x) + c->x;
    r.y = ((b->y + a->y) + c->y) * 0.33333334f;
    r.z = (z1 + c->z) * 0.33333334f;
    *px = *px * 0.33333334f;
    *out = r;
    return out;
}
