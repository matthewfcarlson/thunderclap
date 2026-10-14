// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001b4770 @ 0x001b4770
// FUN_001b4770 @ 0x001b4770: centroid of one triangle of a mesh
struct Vec3 {
    float x, y, z;
};

struct Triangle {
    char pad00[0x10];
    unsigned short a, b, c;
    char pad16[2];
};

struct Mesh {
    char pad00[8];
    Vec3 *vertices;
    char pad0c[0xc];
    Triangle *triangles;
};

struct Model {
    char pad00[0x44];
    Mesh *mesh;
};

void __stdcall FUN_001b4770(Vec3 *out, Model *model, unsigned short index)
{
    Mesh *mesh = model->mesh;
    Triangle *t = &mesh->triangles[index];
    Vec3 *a = &mesh->vertices[t->a];
    Vec3 *b = &mesh->vertices[t->b];
    Vec3 *c = &mesh->vertices[t->c];
    volatile float sumX = a->x + b->x + c->x;
    volatile float sumZ01 = a->z + b->z;
    out->x = sumX * 0.33333334f;
    out->y = (a->y + b->y + c->y) * 0.33333334f;
    out->z = (sumZ01 + c->z) * 0.33333334f;
}
