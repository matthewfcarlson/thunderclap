// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_003430f0 @ 0x003430f0
// Post-twiddle butterfly pass of a split-radix transform: dispatches on the block size (0x80 or not).
// equiv-conv: FUN_00341bd0 ecx eax
void FUN_00341bd0(float *tw, float *data);
// equiv-conv: FUN_00342180 ecx eax
void FUN_00342180(float *tw, float *data);
// equiv-conv: FUN_00342800 ecx eax
void FUN_00342800(float *tw, float *data);
// equiv-conv: FUN_003429f0 ecx eax
void FUN_003429f0(float *tw, float *data);

// equiv-conv: FUN_003430f0 eax esi edx ebx
void FUN_003430f0(int n, float *data, float *table, int index)
{
    if (n == 0x80) {
        float *tw = table + index - 8;
        FUN_00341bd0(tw, data);
        FUN_00342180(table + index - 32, data + 32);
        FUN_00341bd0(tw, data + 64);
        FUN_00341bd0(tw, data + 96);
    } else {
        float *tw = table + index - 16;
        FUN_00342800(tw, data);
        FUN_003429f0(tw, data + 16);
        FUN_00342800(tw, data + 32);
        FUN_00342800(tw, data + 48);
    }
}
