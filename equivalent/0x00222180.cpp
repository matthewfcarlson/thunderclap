// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00222180 @ 0x00222180
struct Arg {
    char pad0[4];
    int f4;                     // 0x04
};

float __cdecl FUN_000189c0(int v);
float __cdecl FUN_00224f10(Arg *a);

struct Pos {
    int x, y, z;
};

struct Mat {
    float m[12];
    Pos pos;                    // 0x30
    float tw;
    void FUN_0022b980();
    void FUN_0022ba30(float angle);
    void FUN_0022ba70(float angle);
    void FUN_0022ca90(Mat *a, Mat *b);
};

class Node {
public:
    Mat mat;
    char pad40[0x10];
    int state;                  // 0x50
    void FUN_00222180(Arg *a);
};

void Node::FUN_00222180(Arg *a)
{
    struct Frame {
        Pos saved;
        Mat tilt;
        Mat product;
    } fr;
    fr.saved = mat.pos;
    mat.FUN_0022b980();
    mat.FUN_0022ba30(FUN_000189c0(a->f4));
    fr.tilt.FUN_0022b980();
    fr.tilt.FUN_0022ba70(FUN_00224f10(a));
    fr.product.FUN_0022ca90(&mat, &fr.tilt);
    mat = fr.product;
    mat.pos = fr.saved;
    state = 2;
}
