// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001b8e40 @ 0x001b8e40
struct V3 { float x, y, z; };
struct Id64 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af50();
    Id64* FUN_0027b0e0(const char* name);
};
struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022be40(const V3* v);
};
struct Spawned;
struct Spawner {
    Spawned* FUN_00283a40(Id64* id, Matrix* mat, float a, float b);
};
Spawner* FUN_0027f250();

Spawned* __stdcall FUN_001b8e40(const char* name, float x, float y, float z) {
    Spawner* spawner = FUN_0027f250();
    union {
        V3 pos;
        Id64 id;
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
