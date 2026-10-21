// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// FUN_001b4770 @ 0x001b4770
// FUN_001b4770 @ 0x001b4770: centroid of one triangle of a mesh
struct Vec3_1b4770 {
    float x, y, z;
};

struct Triangle_1b4770 {
    char pad00[0x10];
    unsigned short a, b, c;
    char pad16[2];
};

struct Mesh_1b4770 {
    char pad00[8];
    Vec3_1b4770 *vertices;
    char pad0c[0xc];
    Triangle_1b4770 *triangles;
};

struct Model_1b4770 {
    char pad00[0x44];
    Mesh_1b4770 *mesh;
};

void __stdcall FUN_001b4770(Vec3_1b4770 *out, Model_1b4770 *model, unsigned short index)
{
    Mesh_1b4770 *mesh = model->mesh;
    Triangle_1b4770 *t = &mesh->triangles[index];
    Vec3_1b4770 *a = &mesh->vertices[t->a];
    Vec3_1b4770 *b = &mesh->vertices[t->b];
    Vec3_1b4770 *c = &mesh->vertices[t->c];
    volatile float sumX = a->x + b->x + c->x;
    volatile float sumZ01 = a->z + b->z;
    Vec3_1b4770 r; // the original builds the result in a frame temporary and copies it, so out may alias the vertices
    r.x = sumX * 0.33333334f;
    r.y = (a->y + b->y + c->y) * 0.33333334f;
    r.z = (sumZ01 + c->z) * 0.33333334f;
    *out = r;
}
