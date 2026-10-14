struct Vec3_1a55d0 {
    float x, y, z;
};
struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022ba70(float angle);
    void FUN_0022be40(const Vec3_1a55d0* value);
    void FUN_0022c2b0(const Vec3_1a55d0* input, Vec3_1a55d0* output);
    void FUN_0022c3b0(const Vec3_1a55d0* input, Vec3_1a55d0* output);
};
struct Node {
    char pad[0xd0];
    Vec3_1a55d0 position;
    Vec3_1a55d0 direction;
    Vec3_1a55d0 up;
    void FUN_00293af0(const Vec3_1a55d0*);
    void FUN_00293a90(const Vec3_1a55d0*);
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
    transform.FUN_0022ba70(angle + offset);
    transform.FUN_0022be40(&pivot);
    Node* target = (Node*)FUN_00344e74(node, 0, &DAT_0049e11c, &DAT_004a0a40, 0);
    Vec3_1a55d0 position = target->position;
    Vec3_1a55d0 direction = target->direction;
    Vec3_1a55d0 up = target->up;
    Vec3_1a55d0 newPosition, newDirection, newUp;
    transform.FUN_0022c2b0(&position, &newPosition);
    transform.FUN_0022c3b0(&direction, &newDirection);
    transform.FUN_0022c3b0(&up, &newUp);
    target->FUN_00293af0(&newPosition);
    target->FUN_00293a90(&newDirection);
    target->FUN_00293ac0(&newUp);
}
