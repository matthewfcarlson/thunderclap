// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001e58d0 @ 0x001e58d0
struct Vec3_1e58d0 { float x, y, z; };

struct Builder {
    void FUN_001e5540(const char* a, const char* b, Vec3_1e58d0 v1, Vec3_1e58d0 v2);
    void FUN_001e58d0(const char* a, const char* b, Vec3_1e58d0 v1, Vec3_1e58d0 v2);
};

void Builder::FUN_001e58d0(const char* a, const char* b, Vec3_1e58d0 v1, Vec3_1e58d0 v2) {
    FUN_001e5540(a, b, v1, v2);
}
