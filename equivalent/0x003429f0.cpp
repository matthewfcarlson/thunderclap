// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003429f0 @ 0x003429f0
struct Block16 {
    float v[16];
};

struct Twiddle {
    int pad0;
    float c1;
    char pad8[8];
    float c2;
    float c3;
    // data block arrives in eax
    void FUN_003429f0(Block16 *d);
};

// equiv-conv: FUN_003429f0 ecx eax
void Twiddle::FUN_003429f0(Block16 *d)
{
    float *v = d->v;
    float fVar1 = c1;
    float fVar2 = c2;
    float fVar3 = c3;
    float fVar4 = v[0];
    float fVar5 = v[1];
    float fVar6 = v[9];
    float fVar7 = v[0];
    float fVar8 = v[1];
    float fVar9 = v[8];
    float fVar10 = ((v[4] - v[13]) - (v[12] + v[5])) * fVar1;
    float fVar11 = (v[12] + v[5] + (v[4] - v[13])) * fVar1;
    float fVar12 = ((v[13] + v[4]) - (v[5] - v[12])) * fVar1;
    fVar1 = ((v[5] - v[12]) + v[13] + v[4]) * fVar1;
    float fVar19 = (v[2] - v[11]) * fVar2 - (v[3] + v[10]) * fVar3;
    float fVar18 = (v[3] + v[10]) * fVar2 + (v[2] - v[11]) * fVar3;
    float fVar17 = (v[11] + v[2]) * fVar3 - (v[3] - v[10]) * fVar2;
    float fVar16 = (v[11] + v[2]) * fVar2 + (v[3] - v[10]) * fVar3;
    float fVar15 = (v[6] - v[15]) * fVar3 - (v[7] + v[14]) * fVar2;
    float fVar14 = (v[6] - v[15]) * fVar2 + (v[7] + v[14]) * fVar3;
    float fVar13 = (v[15] + v[6]) * fVar2 - (v[7] - v[14]) * fVar3;
    fVar2 = (v[7] - v[14]) * fVar2 + (v[15] + v[6]) * fVar3;
    fVar3 = fVar10 + (fVar4 - v[9]);
    float fVar21 = fVar11 + v[8] + fVar5;
    float fVar20 = fVar15 + fVar19;
    float fVar22 = fVar14 + fVar18;
    v[0] = fVar20 + fVar3;
    v[1] = fVar22 + fVar21;
    v[2] = fVar3 - fVar20;
    v[3] = fVar21 - fVar22;
    fVar10 = (fVar4 - v[9]) - fVar10;
    fVar11 = (v[8] + fVar5) - fVar11;
    fVar19 = fVar19 - fVar15;
    fVar18 = fVar18 - fVar14;
    v[4] = fVar10 - fVar18;
    v[5] = fVar19 + fVar11;
    v[6] = fVar18 + fVar10;
    v[7] = fVar11 - fVar19;
    fVar4 = (fVar6 + fVar7) - fVar1;
    fVar10 = fVar12 + (fVar8 - fVar9);
    fVar5 = fVar17 - fVar13;
    fVar3 = fVar16 - fVar2;
    v[8] = fVar5 + fVar4;
    v[9] = fVar3 + fVar10;
    v[10] = fVar4 - fVar5;
    v[11] = fVar10 - fVar3;
    fVar1 = fVar1 + fVar6 + fVar7;
    fVar12 = (fVar8 - fVar9) - fVar12;
    fVar13 = fVar13 + fVar17;
    fVar2 = fVar2 + fVar16;
    v[12] = fVar1 - fVar2;
    v[13] = fVar13 + fVar12;
    v[14] = fVar2 + fVar1;
    v[15] = fVar12 - fVar13;
}
