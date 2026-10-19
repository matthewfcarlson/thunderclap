// STATUS: equivalent (tools/equiv.py level 3: 125 inputs, branch coverage 38/42, incomplete)
// FUN_002b57d0 @ 0x002b57d0
struct V3 {
    float x, y, z;
};
struct Mat {
    float m[16];
    void FUN_0022ca90(const Mat* a, const Mat* b);
};
struct Rec0 {
    float x, y, z;
    short idx;
    unsigned char c0;
    unsigned char pad0f;
    unsigned int pad10;
};
struct Rec1 {
    float x, y, z;
    short idx;
    unsigned short pad0e;
    float w0, w1;
    unsigned char c0, c1;
    unsigned short pad1a;
};
struct Rec2 {
    float x, y, z;
    short idx;
    unsigned short pad0e;
    float w0, w1, w2;
    unsigned char c0, c1, c2, c3;
};
struct TriIdx {
    unsigned short a, b, c;
    unsigned short pad[3];
};
struct Topo {
    char pad00[8];
    Rec0* r0;
    Rec1* r1;
    Rec2* r2;
    int n0;
    int n1;
    int n2;
};
struct Skel {
    char pad00[0xc];
    unsigned int count;
    char pad10[0x1c - 0x10];
    Mat* mats;
    void FUN_00284820(int z);
};
struct SrcMats {
    char pad00[0x10];
    unsigned int count;
    char pad14[0x20 - 0x14];
    Mat* mats;
};
struct IdxBuf {
    char pad00[0xc];
    int count;
    TriIdx* tris;
};
struct OutBuf {
    char pad00[0x10];
    V3* verts;
    V3* normals;
};
namespace pure3d {
class ShadowMeshImpl {
  public:
    char pad00[0x44];
    IdxBuf* idx;
    OutBuf* out;
    char pad4c[0x70 - 0x4c];
    SrcMats* src;
    Mat* cache;
    Topo* topo;
    void FUN_002b4b40(Skel* s);
    void vfunc_6();
    void Update(Skel* arg);
};
} // namespace pure3d
#define XG_X(M, x, y, z) (((y) * (M)->m[4] + (z) * (M)->m[8]) + (x) * (M)->m[0] + (M)->m[12])
#define XG_Y(M, x, y, z) (((y) * (M)->m[5] + (x) * (M)->m[1]) + (z) * (M)->m[9] + (M)->m[13])
#define XG_Z(M, x, y, z) (((y) * (M)->m[6] + (x) * (M)->m[2]) + (z) * (M)->m[10] + (M)->m[14])
#define XF_X(M, x, y, z) ((z) * (M)->m[8] + (y) * (M)->m[4] + (x) * (M)->m[0] + (M)->m[12])
#define XF_Y(M, x, y, z) ((z) * (M)->m[9] + (y) * (M)->m[5] + (x) * (M)->m[1] + (M)->m[13])
#define XF_Z(M, x, y, z) ((z) * (M)->m[10] + (y) * (M)->m[6] + (x) * (M)->m[2] + (M)->m[14])

void pure3d::ShadowMeshImpl::Update(Skel* arg) {
    if (!arg)
        return;
    arg->FUN_00284820(0);
    unsigned int cnt = src->count;
    if (arg->count < cnt)
        cnt = arg->count;
    bool changed = false;
    if (cnt != 0) {
        for (unsigned int i = 0; i < cnt; i++) {
            Mat transformed;
            transformed.FUN_0022ca90(&src->mats[i], &arg->mats[i]);
            if (!changed) {
                for (int r = 0; r < 4 && !changed; r++) {
                    for (int c = 0; c < 4; c++) {
                        if (!(transformed.m[r * 4 + c] == cache[i].m[r * 4 + c])) {
                            changed = true;
                            break;
                        }
                    }
                }
            }
            cache[i] = transformed;
        }
        if (changed) {
            IdxBuf* ib = idx;
            int nt = ib->count;
            TriIdx* tris = ib->tris;
            OutBuf* ob = out;
            V3* ov = ob->verts;
            V3* nrms = ob->normals;
            Topo* T = topo;
            Rec0* R0 = T->r0;
            Rec1* R1 = T->r1;
            Rec2* R2 = T->r2;
            int N0 = T->n0;
            int N1 = T->n1;
            int N2 = T->n2;
            for (int j = 0; j < N2; j++) {
                Rec2* r = &R2[j];
                Mat* M0 = &cache[r->c0];
                double rx = XG_X(M0, r->x, r->y, r->z) * r->w0;
                volatile float ry = (float)(XG_Y(M0, r->x, r->y, r->z) * r->w0);
                volatile float rz = (float)(XG_Z(M0, r->x, r->y, r->z) * r->w0);
                Mat* M1 = &cache[r->c1];
                float w1 = r->w1;
                rx = XG_X(M1, r->x, r->y, r->z) * w1 + rx;
                ry = (float)(XG_Y(M1, r->x, r->y, r->z) * w1 + ry);
                rz = (float)(XG_Z(M1, r->x, r->y, r->z) * w1 + rz);
                Mat* M2 = &cache[r->c2];
                float w2 = r->w2;
                rx = XG_X(M2, r->x, r->y, r->z) * w2 + rx;
                double ry2 = XG_Y(M2, r->x, r->y, r->z) * w2 + ry;
                rz = (float)(XG_Z(M2, r->x, r->y, r->z) * w2 + rz);
                V3* o = &ov[r->idx];
                o->x = (float)rx;
                o->y = (float)ry2;
                o->z = rz;
            }
            for (int j = 0; j < N1; j++) {
                Rec1* r = &R1[j];
                Mat* M0 = &cache[r->c0];
                volatile float x0 = (float)(XG_X(M0, r->x, r->y, r->z) * r->w0);
                volatile float y0 = (float)(XG_Y(M0, r->x, r->y, r->z) * r->w0);
                double z0 = XG_Z(M0, r->x, r->y, r->z) * r->w0;
                Mat* M1 = &cache[r->c1];
                float w1 = r->w1;
                V3* o = &ov[r->idx];
                float xo = (float)(XG_X(M1, r->x, r->y, r->z) * w1 + x0);
                float yo = (float)(XG_Y(M1, r->x, r->y, r->z) * w1 + y0);
                volatile float zo = (float)(XG_Z(M1, r->x, r->y, r->z) * w1 + z0);
                o->x = xo;
                o->z = zo;
                o->y = yo;
            }
            for (int j = 0; j < N0; j++) {
                Rec0* r = &R0[j];
                Mat* M0 = &cache[r->c0];
                V3* o = &ov[r->idx];
                float xo = (float)XF_X(M0, r->x, r->y, r->z);
                float yo = (float)XF_Y(M0, r->x, r->y, r->z);
                volatile float zo = (float)XF_Z(M0, r->x, r->y, r->z);
                o->x = xo;
                o->z = zo;
                o->y = yo;
            }
            for (int t = 0; t < nt; t++) {
                TriIdx* ti = &tris[t];
                V3* pa = &ov[ti->a];
                V3* pb = &ov[ti->b];
                V3* pc = &ov[ti->c];
                double ex = pb->x - pa->x;
                double ey = pb->y - pa->y;
                double ez = pb->z - pa->z;
                volatile float fx = pc->x - pb->x;
                volatile float fy = pc->y - pb->y;
                double fz = pc->z - pb->z;
                V3* nrm = &nrms[t];
                nrm->x = (float)(fz * ey - fy * ez);
                nrm->y = (float)(ez * fx - fz * ex);
                nrm->z = (float)(fy * ex - fx * ey);
            }
        }
    }
    FUN_002b4b40(arg);
    vfunc_6();
}