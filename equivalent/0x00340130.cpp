// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00340130 @ 0x00340130
struct Quad_340130 {
    unsigned int w[16];
};

// Rotates the 16-word block: words 4..7 stay as w[4],w[5] -> w[12],w[13], and so on.
// equiv-conv: FUN_00340130 eax
void FUN_00340130(Quad_340130 *p)
{
    unsigned int t0 = p->w[4];
    unsigned int t1 = p->w[5];
    unsigned int t2 = p->w[8];
    unsigned int t3 = p->w[9];
    float f2 = *(float *)&p->w[2];
    float f3 = *(float *)&p->w[3];
    *(float *)&p->w[8] = f2;
    *(float *)&p->w[9] = f3;
    p->w[2] = p->w[14];
    p->w[3] = p->w[15];
    p->w[4] = p->w[6];
    p->w[5] = p->w[7];
    p->w[6] = p->w[10];
    p->w[7] = p->w[11];
    p->w[10] = p->w[12];
    p->w[11] = p->w[13];
    p->w[12] = t0;
    p->w[13] = t1;
    p->w[14] = t2;
    p->w[15] = t3;
}
