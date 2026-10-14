// STATUS: equivalent (tools/equiv.py level 3: 13867 inputs, branch coverage 22/22)
// CPatrolPathManager::vfunc_1 @ 0x001065b0
// CPatrolPathManager::vfunc_1 @ 0x001065b0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0

struct V3_1065b0 {
    float x, y, z;
};

struct Mat4_1065b0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022be60(float x, float y, float z);
    void FUN_0022be40(const V3_1065b0 *pos);
    void FUN_0022ca90(const Mat4_1065b0 *a, const Mat4_1065b0 *b);
    void FUN_0022c2b0(V3_1065b0 *in, V3_1065b0 *out);
};

struct NameHolder_1065b0 {
    char data[8];
    void FUN_0027b040(const char *name);
};

struct Table_1065b0 {
    int FUN_00337130(const char *name);
};

struct Element_1065b0 {
    char pad0[4];
    Table_1065b0 *table;
    char pad8[4];
    const char *name;
    char FUN_003358a0(int index, int *out);
    void FUN_00336600(const char *attr, float *x, float *y, float *z);
    char FUN_00335cc0(int index, int i, float *x, float *y, float *z);
    char FUN_003364f0(const char *attr, int *out);
};

struct PathPoint_1065b0 {
    float x, y, z;
    int next;
    float weight;
    int f14;
    int f18;
    int f1c;
    int f20;
};

class __declspec(novtable) PathBase {
public:
    virtual void v0();
    char pad04[4];
    NameHolder_1065b0 name;
    void FUN_0027b070();
    PathBase() { FUN_0027b070(); }
};

void *thunk_FUN_0008d690(unsigned int size);
void *FUN_0008d6d0(unsigned int size);
inline void *operator new(unsigned int, void *p) throw() { return p; }

class CPatrolPath : public PathBase {
public:
    PathPoint_1065b0 *points;   // 0x10
    int count;           // 0x14
    char closed;         // 0x18
    virtual void v1();
    CPatrolPath(int n);
};

CPatrolPath::CPatrolPath(int n)
{
    closed = 0;
    points = (PathPoint_1065b0 *)FUN_0008d6d0(n * sizeof(PathPoint_1065b0));
    count = n;
}

struct Sub_1065b0 {
    char FUN_001cd010();
};

struct Globals_1065b0 {
    char pad[0x2c];
    Sub_1065b0 *sub;
};
extern Globals_1065b0 *DAT_004dd700;

class CPatrolPathManager {
public:
    char pad[4];
    int FUN_001062d0(CPatrolPath *p);
    char vfunc_1(Element_1065b0 *elem);
};

struct PatrolFrame {
    char pad10[3];
    char closed;            // 0x13
    int n;                  // 0x14
    union {
        const char *pathName;
        float a;
    } u18;                  // 0x18
    V3_1065b0 pos;                 // 0x1c
    V3_1065b0 v;                   // 0x28
    int idx;                // 0x34
    float b;                // 0x38
    float c;                // 0x3c
    float sx;               // 0x40
    char pad44[4];
    float ty;               // 0x48
    float rx;               // 0x4c
    float rz;               // 0x50
    float sz;               // 0x54
    float ry;               // 0x58
    float tz;               // 0x5c
    int form;               // 0x60
    float tx;               // 0x64
    float sy;               // 0x68
    Mat4_1065b0 tmp;               // 0x6c
    Mat4_1065b0 rot;               // 0xac
    Mat4_1065b0 moveM;             // 0xec
    Mat4_1065b0 scaleM;            // 0x12c
    Mat4_1065b0 full;              // 0x16c
};

char CPatrolPathManager::vfunc_1(Element_1065b0 *elem)
{
    if (DAT_004dd700->sub->FUN_001cd010())
        return 1;

    PatrolFrame f;
    f.u18.pathName = elem->name;
    f.idx = elem->table->FUN_00337130("controlPoints");
    elem->FUN_003358a0(f.idx, &f.n);

    elem->FUN_00336600("translate", &f.tx, &f.ty, &f.tz);
    elem->FUN_00336600("rotate", &f.rx, &f.ry, &f.rz);
    elem->FUN_00336600("scale", &f.sx, &f.sy, &f.sz);

    f.rot.FUN_0022b980();
    f.rot.FUN_0022bc20(f.rx * -0.017453292f, f.ry * -0.017453292f, f.rz * 0.017453292f);
    f.scaleM.FUN_0022b980();
    f.scaleM.FUN_0022be60(f.sx, f.sy, f.sz);
    f.moveM.FUN_0022b980();
    f.pos.x = f.tx;
    f.pos.y = f.ty;
    f.pos.z = -f.tz;
    f.moveM.FUN_0022be40(&f.pos);
    f.tmp.FUN_0022ca90(&f.rot, &f.scaleM);
    f.full.FUN_0022ca90(&f.tmp, &f.moveM);
    f.tmp = f.full;

    int n = f.n;
    void *mem = thunk_FUN_0008d690(0x20);
    CPatrolPath *path = 0;
    if (mem)
        path = new (mem) CPatrolPath(n);
    path->v0();
    path->name.FUN_0027b040(f.u18.pathName);

    elem->FUN_003364f0("form", &f.form);
    f.closed = f.form != 0;
    path->closed = f.closed;

    for (int i = 0; i < f.n; i++) {
        elem->FUN_00335cc0(f.idx, i, &f.u18.a, &f.b, &f.c);
        f.v.x = f.u18.a;
        f.v.y = f.b;
        f.v.z = -f.c;
        f.tmp.FUN_0022c2b0(&f.v, &f.v);
        if (i < path->count) {
            PathPoint_1065b0 *pt = &path->points[i];
            pt->x = f.v.x;
            pt->y = f.v.y;
            pt->z = f.v.z;
        }
        // path->points is re-read before every store: a fuzzed allocation can overlap the path itself
        if (i == f.n - 1) {
            if (f.closed) {
                if (i < path->count) {
                    path->points[i].next = 0;
                    path->points[i].f14 = 0;
                    path->points[i].f18 = 0;
                    path->points[i].f20 = 0;
                    path->points[i].f1c = 0;
                    path->points[i].weight = 0.5f;
                }
            } else {
                if (i < path->count) {
                    path->points[i].next = -1;
                    path->points[i].f14 = 0;
                    path->points[i].f18 = 0;
                    path->points[i].f20 = 0;
                    path->points[i].f1c = 0;
                    path->points[i].weight = 0.5f;
                }
            }
        } else if (i < path->count) {
            path->points[i].next = i + 1;
            path->points[i].f14 = 0;
            path->points[i].f18 = 0;
            path->points[i].f20 = 0;
            path->points[i].f1c = 0;
            path->points[i].weight = 0.5f;
        }
    }
    FUN_001062d0(path);
    path->v1();
    return 1;
}
