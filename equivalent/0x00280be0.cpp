// STATUS: equivalent (tools/equiv.py level 3: 60 inputs, branch coverage 14/14)
// FUN_00280be0 @ 0x00280be0
struct Vtx {
    float x, y, z;
    int w0, w1, w2;
    void FUN_0027f070(Vtx* a, Vtx* b, float t);
};

struct Plane {
    float nx, ny, nz;
    float d;
    void FUN_0022e1f0(Vtx* a, Vtx* b, float* t);
};

// Sutherland-Hodgman clip of a closed polygon against one plane.
void FUN_00280be0(Plane* plane, Vtx* verts, int count, Vtx* out, int* outCount)
{
    bool prevInside = (-plane->d >= (verts->z * plane->nz + verts->y * plane->ny + plane->nx * verts->x));
    struct { float tOutgoing; float unused; float tIncoming; } f;
    *outCount = 0;
    for (int i = 1; i <= count; i++) {
        Vtx* prev = &verts[i - 1];
        Vtx* cur = &verts[i % count];
        bool curInside = (-plane->d >= (cur->z * plane->nz + cur->y * plane->ny + plane->nx * cur->x));
        if (prevInside) {
            if (!curInside) {
                Vtx* dst = &out[*outCount];
                plane->FUN_0022e1f0(prev, cur, &f.tOutgoing);
                dst->FUN_0027f070(prev, cur, f.tOutgoing);
                (*outCount)++;
            } else {
                out[*outCount] = *cur;
                (*outCount)++;
            }
        } else if (curInside) {
            Vtx* dst = &out[*outCount];
            plane->FUN_0022e1f0(prev, cur, &f.tIncoming);
            dst->FUN_0027f070(prev, cur, f.tIncoming);
            (*outCount)++;
            out[*outCount] = *cur;
            (*outCount)++;
        }
        prevInside = curInside;
    }
}
