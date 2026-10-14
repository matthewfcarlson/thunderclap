// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001e57e0 @ 0x001e57e0
struct Vec3 {
    float x, y, z;
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};

class Spawner {
public:
    void FUN_001e5540(int a, int b, Vec3 pos, Vec3 offset);
    void FUN_001e57e0(int a, int b, Vec3 pos);
};

void Spawner::FUN_001e57e0(int a, int b, Vec3 pos) {
    FUN_001e5540(a, b, pos, Vec3(0.0f, 0.0f, 0.0f));
}
