// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 2/2)
// FUN_003430f0 @ 0x003430f0
// FUN_003430f0 @ 0x003430f0
// Post-twiddle butterfly pass of a split-radix transform: dispatches on the block size (0x80 or not).
// equiv-conv: FUN_00341bd0 eax ecx
void FUN_00341bd0(float *data, float *tw);
// equiv-conv: FUN_00342180 eax ecx
void FUN_00342180(float *data, float *tw);
struct ThisNote_00342800 {
    // equiv-conv: FUN_00342800 ecx eax
    void FUN_00342800(float *data);
};
struct ThisNote_003429f0 {
    // equiv-conv: FUN_003429f0 ecx eax
    void FUN_003429f0(float *data);
};

// equiv-conv: FUN_003430f0 eax esi edx ebx
void FUN_003430f0(int n, float *data, float *table, int index)
{
    if (n == 0x80) {
        float *tw = table + index - 8;
        FUN_00341bd0(data, tw);
        FUN_00342180(data + 32, table + index - 32);
        FUN_00341bd0(data + 64, tw);
        FUN_00341bd0(data + 96, tw);
    } else {
        float *tw = table + index - 16;
        ((ThisNote_00342800*)(tw))->FUN_00342800(data);
        ((ThisNote_003429f0*)(tw))->FUN_003429f0(data + 16);
        ((ThisNote_00342800*)(tw))->FUN_00342800(data + 32);
        ((ThisNote_00342800*)(tw))->FUN_00342800(data + 48);
    }
}
