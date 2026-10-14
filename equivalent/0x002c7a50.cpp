// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 46/46)
// FUN_002c7a50 @ 0x002c7a50
// equiv-conv: FUN_002c7a50 ecx eax esi

struct Vec3 {
    float x, y, z;
};

struct Source {
    char pad00[8];
    unsigned int format;
    unsigned int count;
    char pad10[8];
    Vec3* pos;
    Vec3* normal;
    Vec3* altPos;
    Vec3* altNormal;
    char pad28[0x38 - 0x28];
    float* uv0;
    float* uv1;
    float* uv2;
    float* uv3;
    int* color0;
    int* color1;
};

struct Vertex {
    float x, y, z;
};

struct Emitter {
    char pad00[8];
    Vertex* pos;
    Vertex* normal;
    int* color;
    float* uv;
    void FUN_0008ef00();
    void FUN_000c7940(Vec3* pos, int color, float* uv);
};

void FUN_002c7a50(unsigned char alt, Source* src, Emitter* out)
{
    unsigned int n = src->count;
    Vec3* pos;
    Vec3* nrm;
    if (alt == 1) {
        pos = src->altPos;
        nrm = src->altNormal;
    } else {
        pos = src->pos;
        nrm = src->normal;
    }
    float* uv3 = src->uv3;
    int* c8 = src->color0;
    int* c4 = src->color1;
    float* u0 = src->uv0;
    float* u1 = src->uv1;
    float* u2 = src->uv2;
    unsigned int fmt = src->format;
    fmt = fmt & 0xfffc7fff;

    if (fmt == 0x2020) {
        for (unsigned int i = 0; i < n; i++) {
            int* v = (int*)out->pos;
            int px = ((int*)&pos[i])[0];
            int col = c8[i];
            v[0] = px;
            v[1] = ((int*)&pos[i])[1];
            v[2] = ((int*)&pos[i])[2];
            out->color[0] = col;
            out->FUN_0008ef00();
        }
    } else if (fmt == 0x2010) {
        for (unsigned int i = 0; i < n; i++) {
            int* v = (int*)out->pos;
            v[0] = ((int*)&pos[i])[0];
            v[1] = ((int*)&pos[i])[1];
            v[2] = ((int*)&pos[i])[2];
            int* nv = (int*)out->normal;
            nv[0] = ((int*)&nrm[i])[0];
            nv[1] = ((int*)&nrm[i])[1];
            nv[2] = ((int*)&nrm[i])[2];
            out->FUN_0008ef00();
        }
    } else if (fmt == 0x2011) {
        for (unsigned int i = 0; i < n; i++) {
            int* v = (int*)out->pos;
            v[0] = ((int*)&pos[i])[0];
            v[1] = ((int*)&pos[i])[1];
            v[2] = ((int*)&pos[i])[2];
            int* nv = (int*)out->normal;
            nv[0] = ((int*)&nrm[i])[0];
            nv[1] = ((int*)&nrm[i])[1];
            nv[2] = ((int*)&nrm[i])[2];
            int* uv = (int*)out->uv;
            uv[0] = ((int*)&u0[i * 2])[0];
            uv[1] = ((int*)&u0[i * 2])[1];
            out->FUN_0008ef00();
        }
    } else if (fmt == 0x2001 || fmt == 0x2021) {
        if (n == 0)
            return;
        if (fmt == 0x2001) {
            int* v = (int*)out->pos;
            v[0] = ((int*)&pos[0])[0];
            v[1] = ((int*)&pos[0])[1];
            v[2] = ((int*)&pos[0])[2];
            int* uv = (int*)out->uv;
            uv[0] = ((int*)u0)[0];
            uv[1] = ((int*)u0)[1];
            out->FUN_0008ef00();
        }
        for (unsigned int i = 0; i < n; i++)
            out->FUN_000c7940(&pos[i], c8[i], &u0[i * 2]);
    } else {
        for (unsigned int i = 0; i < n; i++) {
            if (nrm) {
                float ny = nrm[i].y;
                float nz = nrm[i].z;
                int nx = ((int*)&nrm[i])[0];
                ((int*)out->normal)[0] = nx;
                out->normal->y = ny;
                out->normal->z = nz;
            }
            if (c8)
                out->color[0] = c8[i];
            if (c4)
                out->color[1] = c4[i];
            if (u0) {
                float uy = u0[i * 2 + 1];
                int ux = ((int*)&u0[i * 2])[0];
                ((int*)out->uv)[0] = ux;
                out->uv[1] = uy;
            }
            if (u1) {
                float uy = u1[i * 2 + 1];
                int ux = ((int*)&u1[i * 2])[0];
                ((int*)out->uv)[2] = ux;
                out->uv[3] = uy;
            }
            if (u2) {
                float uy = u2[i * 2 + 1];
                int ux = ((int*)&u2[i * 2])[0];
                ((int*)out->uv)[4] = ux;
                out->uv[5] = uy;
            }
            if (uv3) {
                float uy = uv3[i * 2 + 1];
                int ux = ((int*)&uv3[i * 2])[0];
                ((int*)out->uv)[6] = ux;
                out->uv[7] = uy;
            }
            float pz = pos[i].z;
            float py = pos[i].y;
            int px = ((int*)&pos[i])[0];
            ((int*)out->pos)[0] = px;
            out->pos->y = py;
            out->pos->z = pz;
            out->FUN_0008ef00();
        }
    }
}
