// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001e57e0 @ 0x001e57e0
struct Vec3_1e57e0 {
    float x, y, z;
    Vec3_1e57e0(float a, float b, float c) : x(a), y(b), z(c) {}
};

class Spawner_1e57e0 {
public:
    void FUN_001e5540(int a, int b, Vec3_1e57e0 pos, Vec3_1e57e0 offset);
    void FUN_001e57e0(int a, int b, Vec3_1e57e0 pos);
};

void Spawner_1e57e0::FUN_001e57e0(int a, int b, Vec3_1e57e0 pos) {
    FUN_001e5540(a, b, pos, Vec3_1e57e0(0.0f, 0.0f, 0.0f));
}
