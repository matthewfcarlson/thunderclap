// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 49/56, incomplete)
// FUN_002b3820 @ 0x002b3820
struct V3_2b3820 {
    float x, y, z;
};
struct Tri16 {
    unsigned short a, b, c;
};
struct Edge16_2b3820 {
    unsigned short a, b;
};
extern int DAT_0052cba8;
extern int DAT_0052cbac;
extern Tri16 DAT_0052cbb0[];
extern Edge16_2b3820 DAT_00544bb0[];

struct Mesh_2b3820 {
    char pad0[0xc];
    unsigned int count;
    unsigned short *indices;
    char *facing;
};
struct Geometry {
    char pad0[0x10];
    V3_2b3820 *verts;
    V3_2b3820 *normals;
};

class Shadow {
  public:
    char pad0[0x44];
    Mesh_2b3820 *mesh;
    Geometry *geom;
    char pad4c[0x54 - 0x4c];
    char pointLight;
    char pad55[3];
    V3_2b3820 light;
    void FUN_002b3820();
};

void Shadow::FUN_002b3820()
{
    Mesh_2b3820 *m = mesh;
    unsigned int n = m->count;
    V3_2b3820 *verts = geom->verts;
    V3_2b3820 *normals = geom->normals;
    unsigned short *idx = m->indices;
    char *facing = m->facing;
    unsigned int i;
    if (!pointLight) {
        i = 0;
        if ((int)n >= 4) {
            const V3_2b3820 *p = normals;
            do {
                facing[i] = ((p[0].y * light.y + p[0].z * light.z) + p[0].x * light.x) < 0.0f;
                facing[i + 1] = ((p[1].z * light.z + p[1].x * light.x) + p[1].y * light.y) < 0.0f;
                facing[i + 2] = ((p[2].z * light.z + p[2].y * light.y) + p[2].x * light.x) < 0.0f;
                facing[i + 3] = ((p[3].z * light.z + p[3].y * light.y) + p[3].x * light.x) < 0.0f;
                i += 4;
                p += 4;
            } while (i < n - 3);
        }
        if (i < n) {
            const V3_2b3820 *p = normals + i;
            do {
                facing[i] = ((p->z * light.z + p->x * light.x) + p->y * light.y) < 0.0f;
                i++;
                p++;
            } while (i < n);
        }
    } else {
        V3_2b3820 L = light;
        i = 0;
        if ((int)n >= 4) {
            const V3_2b3820 *p = normals;
            const unsigned short *w = idx;
            do {
                const V3_2b3820 *v0 = &verts[w[0]];
                facing[i] = 0.0f < (((L.z - v0->z) * p[0].z + (L.y - v0->y) * p[0].y) + (L.x - v0->x) * p[0].x);
                const V3_2b3820 *v1 = &verts[w[6]];
                facing[i + 1] = 0.0f < (((L.z - v1->z) * p[1].z + (L.x - v1->x) * p[1].x) + (L.y - v1->y) * p[1].y);
                const V3_2b3820 *v2 = &verts[w[12]];
                facing[i + 2] = 0.0f < (((L.z - v2->z) * p[2].z + (L.y - v2->y) * p[2].y) + (L.x - v2->x) * p[2].x);
                const V3_2b3820 *v3 = &verts[w[18]];
                facing[i + 3] = 0.0f < (((L.z - v3->z) * p[3].z + (L.y - v3->y) * p[3].y) + (L.x - v3->x) * p[3].x);
                i += 4;
                p += 4;
                w += 24;
            } while (i < n - 3);
        }
        if (i < n) {
            const V3_2b3820 *p = normals + i;
            const unsigned short *w = idx + 6 * i;
            do {
                const V3_2b3820 *v0 = &verts[w[0]];
                facing[i] = 0.0f < (((L.z - v0->z) * p->z + (L.x - v0->x) * p->x) + (L.y - v0->y) * p->y);
                i++;
                p++;
                w += 6;
            } while (i < n);
        }
    }
    int edges = 0;
    int tris = 0;
    DAT_0052cbac = 0;
    DAT_0052cba8 = 0;
    if (n != 0) {
        const unsigned short *w = idx;
        for (unsigned int k = 0; k < n; k++, w += 6) {
            if (facing[k] == 0) {
                DAT_0052cbb0[tris].a = w[0];
                DAT_0052cbb0[tris].b = w[1];
                DAT_0052cbb0[tris].c = w[2];
                tris++;
                DAT_0052cbac = tris;
                if (w[3] == 0xffff || facing[w[3]] != 0) {
                    DAT_00544bb0[edges].b = w[0];
                    DAT_00544bb0[edges].a = w[1];
                    edges++;
                    DAT_0052cba8 = edges;
                }
                if (w[4] == 0xffff || facing[w[4]] != 0) {
                    DAT_00544bb0[edges].b = w[1];
                    DAT_00544bb0[edges].a = w[2];
                    edges++;
                    DAT_0052cba8 = edges;
                }
                if (w[5] == 0xffff || facing[w[5]] != 0) {
                    DAT_00544bb0[edges].b = w[2];
                    DAT_00544bb0[edges].a = w[0];
                    edges++;
                    DAT_0052cba8 = edges;
                }
            }
        }
    }
}
