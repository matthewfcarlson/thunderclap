// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00305b00 @ 0x00305b00
struct V3_305b00 {
    float x, y, z;
};

struct Tensor_305b00 {
    float f0;
    float yz2;
    float nxy;
    float nzx;
    float xz2;
    float nyz;
    float xy2;
    void FUN_002fcb80(int a);
};

void __cdecl FUN_00305b00(Tensor_305b00 *out, const V3_305b00 *v, int a)
{
    out->yz2 = v->y * v->y + v->z * v->z;
    out->nxy = -(v->x * v->y);
    out->nzx = -(v->z * v->x);
    out->xz2 = v->x * v->x + v->z * v->z;
    out->nyz = -(v->z * v->y);
    out->xy2 = v->x * v->x + v->y * v->y;
    out->FUN_002fcb80(a);
}
