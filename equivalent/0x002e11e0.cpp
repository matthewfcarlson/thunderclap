// STATUS: equivalent (tools/equiv.py level 3: 22 inputs, branch coverage 8/8)
// FUN_002e11e0 @ 0x002e11e0
#include "compat/ptr.h"
struct V3_2e11e0 {
    float x, y, z;
};

struct Delta {
    int vertex;
    float dx, dy, dz;
};

struct DeltaList {
    char pad0[0x14];
    Delta* begin;
    Delta* end;
};

struct VertexBuffer_2e11e0 {
    char pad0[0x10];
    V3_2e11e0* verts;
};

class Morph {
public:
    char pad0[0x5c];
    VertexBuffer_2e11e0* buffer;

    void FUN_002e11e0(DeltaList* list, float weight);
};

// Adds weight * delta to each referenced vertex.
void Morph::FUN_002e11e0(DeltaList* list, float weight)
{
    hulk_intptr count = list->end - list->begin;
    for (unsigned i = 0; i < (unsigned)count; i++) {
        const Delta* d = &list->begin[i];
        float x = weight * d->dx;
        float y = weight * d->dy;
        float z = weight * d->dz;
        V3_2e11e0* v = &buffer->verts[d->vertex];
        v->x += x;
        v->y += y;
        v->z += z;
    }
}
