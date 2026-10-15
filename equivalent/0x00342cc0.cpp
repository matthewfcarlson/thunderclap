// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00342cc0 @ 0x00342cc0
struct Butterfly_342cc0 {
    float v[8];
};

// equiv-conv: FUN_00342cc0 eax
void FUN_00342cc0(Butterfly_342cc0 *p)
{
    float a = p->v[0] + p->v[4];
    float b = p->v[1] + p->v[5];
    float c = p->v[0] - p->v[4];
    float d = p->v[1] - p->v[5];
    float e = p->v[6] + p->v[2];
    float f = p->v[3] + p->v[7];
    float g = p->v[2] - p->v[6];
    float h = p->v[3] - p->v[7];
    p->v[0] = a + e;
    p->v[1] = b + f;
    p->v[4] = a - e;
    p->v[5] = b - f;
    p->v[2] = h + c;
    p->v[3] = d - g;
    p->v[6] = c - h;
    p->v[7] = g + d;
}
