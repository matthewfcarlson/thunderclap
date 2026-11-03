// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_001fbd00 @ 0x001fbd00
#include "gen/owners.h"
struct V3_1fbd00 {
    float x, y, z;
};

struct Mat4_1fbd00 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022be60(float x, float y, float z);
};

struct NameHolder_1fbd00 {
    char data[8];
};

struct Element_1fbd00 {
    char pad0[0xc];
    const char *name;
    void FUN_00336600(const char *attr, float *x, float *y, float *z);
};

int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);

class Marker_1fbd00 {
public:
    char pad0[8];
    NameHolder_1fbd00 nameHolder;
    char pad10[0x90 - 0x10];
    char label[0x20];
    char padB0[0xce - 0xb0];
    char flagCe;

    void FUN_001fbb80(V3_1fbd00 *origin, V3_1fbd00 *dir, float angle);
    void FUN_001fbd00(Element_1fbd00 *elem);
};

void Marker_1fbd00::FUN_001fbd00(Element_1fbd00 *elem)
{
    const char *name = elem->name;
    ((owners::Target_27b040 *)&nameHolder)->FUN_0027b040((hulk_uintptr)name);
    FUN_000964a0(label, 0x20, "%s", name);
    flagCe = 0;

    V3_1fbd00 up;
    V3_1fbd00 origin;
    float tx, ty, tz;
    float rx, ry, rz;
    float sx, sy, sz;
    up.x = 1.0f;
    up.y = 1.0f;
    up.z = -1.0f;
    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;

    elem->FUN_00336600("translate", &tx, &ty, &tz);
    elem->FUN_00336600("rotate", &rx, &ry, &rz);
    elem->FUN_00336600("scale", &sx, &sy, &sz);

    Mat4_1fbd00 identity;
    Mat4_1fbd00 scaleM;
    Mat4_1fbd00 moveM;
    Mat4_1fbd00 tmp;
    Mat4_1fbd00 full;
    identity.FUN_0022b980();
    scaleM.FUN_0022b980();
    scaleM.FUN_0022be60(sx, sy, sz);
    moveM.FUN_0022b980();
    V3_1fbd00 pos;
    pos.x = tx;
    pos.y = ty;
    pos.z = -tz;
    ((owners::Target_22be40 *)&moveM)->FUN_0022be40((const int *)(const V3_1fbd00 *)(&pos));
    ((owners::Matrix_22ca90 *)&tmp)->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Mat4_1fbd00 *)(&identity), (const owners::Matrix_22ca90 *)(const Mat4_1fbd00 *)(&scaleM));
    ((owners::Matrix_22ca90 *)&full)->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Mat4_1fbd00 *)(&tmp), (const owners::Matrix_22ca90 *)(const Mat4_1fbd00 *)(&moveM));
    tmp = full;
    ((owners::Mat_22c2b0 *)&tmp)->FUN_0022c2b0((float *)(V3_1fbd00 *)(&origin), (float *)(V3_1fbd00 *)(&origin));
    ((owners::Mat_22c2b0 *)&tmp)->FUN_0022c2b0((float *)(V3_1fbd00 *)(&up), (float *)(V3_1fbd00 *)(&up));
    FUN_001fbb80(&origin, &up, ry * -0.0174532924f);
}
