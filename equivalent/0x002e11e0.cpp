// STATUS: equivalent (tools/equiv.py level 3: 22 inputs, branch coverage 8/8)
// FUN_002e11e0 @ 0x002e11e0
struct V3 {
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

struct VertexBuffer {
    char pad0[0x10];
    V3* verts;
};

class Morph {
public:
    char pad0[0x5c];
    VertexBuffer* buffer;

    void FUN_002e11e0(DeltaList* list, float weight);
};

// Adds weight * delta to each referenced vertex.
void Morph::FUN_002e11e0(DeltaList* list, float weight)
{
    int count = list->end - list->begin;
    for (unsigned i = 0; i < (unsigned)count; i++) {
        const Delta* d = &list->begin[i];
        float x = weight * d->dx;
        float y = weight * d->dy;
        float z = weight * d->dz;
        V3* v = &buffer->verts[d->vertex];
        v->x += x;
        v->y += y;
        v->z += z;
    }
}
