#include "gen/owners.h"
struct Vec3_1a55d0 {
    float x, y, z;
};
struct Matrix {
    float m[16];
    void FUN_0022b980();
};
struct Node {
    char pad[0xd0];
    Vec3_1a55d0 position;
    Vec3_1a55d0 direction;
    Vec3_1a55d0 up;
    void FUN_00293ac0(const Vec3_1a55d0*);
};
struct Settings_1a55d0 {
    char pad[0x2c];
    float angle;
};
extern char DAT_0049e11c;
extern char DAT_004a0a40;
extern void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
struct Object {
    char pad[0x1c];
    Settings_1a55d0* settings;
    char pad20[8];
    void* node;
    void FUN_001a54a0(Vec3_1a55d0*, float*);
    void FUN_001a55d0();
};
void Object::FUN_001a55d0() {
    if (!node)
        return;
    Vec3_1a55d0 pivot;
    float offset;
    FUN_001a54a0(&pivot, &offset);
    float angle = settings->angle;
    Matrix transform;
    transform.FUN_0022b980();
    ((owners::Mat_22ba70 *)&transform)->FUN_0022ba70(angle + offset);
    ((owners::Target_22be40 *)&transform)->FUN_0022be40((const int *)(const Vec3_1a55d0 *)(&pivot));
    Node* target = (Node*)FUN_00344e74(node, 0, &DAT_0049e11c, &DAT_004a0a40, 0);
    Vec3_1a55d0 position = target->position;
    Vec3_1a55d0 direction = target->direction;
    Vec3_1a55d0 up = target->up;
    Vec3_1a55d0 newPosition, newDirection, newUp;
    ((owners::Mat_22c2b0 *)&transform)->FUN_0022c2b0((float *)(const Vec3_1a55d0 *)(&position), (float *)(Vec3_1a55d0 *)(&newPosition));
    ((owners::M_22c3b0 *)&transform)->FUN_0022c3b0((float *)(const Vec3_1a55d0 *)(&direction), (float *)(Vec3_1a55d0 *)(&newDirection));
    ((owners::M_22c3b0 *)&transform)->FUN_0022c3b0((float *)(const Vec3_1a55d0 *)(&up), (float *)(Vec3_1a55d0 *)(&newUp));
    ((owners::C_293af0 *)target)->FUN_00293af0((int *)(const Vec3_1a55d0 *)(&newPosition));
    ((owners::C_293a90 *)target)->FUN_00293a90((int *)(const Vec3_1a55d0 *)(&newDirection));
    target->FUN_00293ac0(&newUp);
}
