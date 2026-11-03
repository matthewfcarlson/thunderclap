// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// FUN_00222180 @ 0x00222180
#include "gen/owners.h"
struct Arg_222180 {
    char pad0[4];
    int f4;                     // 0x04
};

float __cdecl FUN_000189c0(int v);
float __cdecl FUN_00224f10(Arg_222180 *a);

struct Pos_222180 {
    int x, y, z;
};

struct Mat_222180 {
    float m[12];
    Pos_222180 pos;                    // 0x30
    float tw;
    void FUN_0022b980();
};

class Node {
public:
    Mat_222180 mat;
    char pad40[0x10];
    int state;                  // 0x50
    void FUN_00222180(Arg_222180 *a);
};

void Node::FUN_00222180(Arg_222180 *a)
{
    struct Frame {
        Pos_222180 saved;
        Mat_222180 tilt;
        Mat_222180 product;
    } fr;
    fr.saved = mat.pos;
    mat.FUN_0022b980();
    ((owners::Matrix_22ba30 *)&mat)->FUN_0022ba30(FUN_000189c0(a->f4));
    fr.tilt.FUN_0022b980();
    ((owners::Mat_22ba70 *)&(fr.tilt))->FUN_0022ba70(FUN_00224f10(a));
    ((owners::Matrix_22ca90 *)&(fr.product))->FUN_0022ca90((const owners::Matrix_22ca90 *)(Mat_222180 *)(&mat), (const owners::Matrix_22ca90 *)(Mat_222180 *)(&fr.tilt));
    mat = fr.product;
    mat.pos = fr.saved;
    state = 2;
}
