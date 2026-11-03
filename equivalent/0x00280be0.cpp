// STATUS: equivalent (tools/equiv.py level 3: 17260 inputs, branch coverage 14/14)
// FUN_00280be0 @ 0x00280be0
#include "gen/owners.h"
struct Vtx_280be0 {
    float x, y, z;
    int w0, w1, w2;
};

struct Plane_280be0 {
    float nx, ny, nz;
    float d;
    void FUN_0022e1f0(Vtx_280be0* a, Vtx_280be0* b, float* t);
};

// Sutherland-Hodgman clip of a closed polygon against one plane.
void FUN_00280be0(Plane_280be0* plane, Vtx_280be0* verts, int count, Vtx_280be0* out, int* outCount)
{
    bool prevInside = (-plane->d >= (verts->z * plane->nz + verts->y * plane->ny + plane->nx * verts->x));
    // the original keeps the destination vertex pointer in the frame word right after each t
    struct { float tOutgoing; Vtx_280be0* dstOut; float tIncoming; Vtx_280be0* dstIn; } f;
    *outCount = 0;
    for (int i = 1; i <= count; i++) {
        Vtx_280be0* prev = &verts[i - 1];
        Vtx_280be0* cur = &verts[i % count];
        bool curInside = (-plane->d >= (cur->z * plane->nz + cur->y * plane->ny + plane->nx * cur->x));
        if (prevInside) {
            if (!curInside) {
                f.dstOut = &out[*outCount];
                plane->FUN_0022e1f0(prev, cur, &f.tOutgoing);
                ((owners::Vertex_27f070 *)(f.dstOut))->FUN_0027f070((const owners::Vertex_27f070 *)(Vtx_280be0 *)prev, (const owners::Vertex_27f070 *)(Vtx_280be0 *)cur, f.tOutgoing);
                (*outCount)++;
            } else {
                out[*outCount] = *cur;
                (*outCount)++;
            }
        } else if (curInside) {
            f.dstIn = &out[*outCount];
            plane->FUN_0022e1f0(prev, cur, &f.tIncoming);
            ((owners::Vertex_27f070 *)(f.dstIn))->FUN_0027f070((const owners::Vertex_27f070 *)(Vtx_280be0 *)prev, (const owners::Vertex_27f070 *)(Vtx_280be0 *)cur, f.tIncoming);
            (*outCount)++;
            out[*outCount] = *cur;
            (*outCount)++;
        }
        prevInside = curInside;
    }
}
