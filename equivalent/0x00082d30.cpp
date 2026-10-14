// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00082d30 @ 0x00082d30
// The matrix is passed in esi.
// equiv-conv: FUN_00082d30 esi
struct Vec3_82d30 {
    float x, y, z;
};

class Matrix {
public:
    void FUN_0022c3b0(const Vec3_82d30* in, Vec3_82d30* out);
    void FUN_0022bec0(const Vec3_82d30* a, const Vec3_82d30* b);
};

struct Frame_82d30 {
    Vec3_82d30 axis;
    Vec3_82d30 input;
};

void FUN_00082d30(Matrix* m) {
    Frame_82d30 f;
    f.input.x = 0.0f;
    f.input.y = 0.0f;
    f.input.z = 1.0f;
    m->FUN_0022c3b0(&f.input, &f.axis);
    f.axis.y = 0.0f;
    if (f.axis.x == 0.0f)
        f.axis.x = 1.0f;
    f.input.x = 0.0f;
    f.input.y = 1.0f;
    f.input.z = 0.0f;
    m->FUN_0022bec0(&f.axis, &f.input);
}
