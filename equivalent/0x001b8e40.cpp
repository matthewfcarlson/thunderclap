// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001b8e40 @ 0x001b8e40
struct V3_1b8e40 { float x, y, z; };
struct Id64_1b8e40 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af50();
    Id64_1b8e40* FUN_0027b0e0(const char* name);
};
struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022be40(const V3_1b8e40* v);
};
struct Spawned;
struct Spawner_1b8e40 {
    Spawned* FUN_00283a40(Id64_1b8e40* id, Matrix* mat, float a, float b);
};
Spawner_1b8e40* FUN_0027f250();

Spawned* __stdcall FUN_001b8e40(const char* name, float x, float y, float z) {
    Spawner_1b8e40* spawner = FUN_0027f250();
    union {
        V3_1b8e40 pos;
        Id64_1b8e40 id;
    } u;
    Matrix mat;
    mat.FUN_0022b980();
    u.pos.x = x;
    u.pos.y = y;
    u.pos.z = z;
    mat.FUN_0022be40(&u.pos);
    u.id.FUN_0027b0e0(name);
    Spawned* result = spawner->FUN_00283a40(&u.id, &mat, -1.0f, 1.0f);
    u.id.FUN_0027af50();
    return result;
}
