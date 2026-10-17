// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00219870 @ 0x00219870
struct Sample { char padding[7]; unsigned char bits; char unused[8]; int base; };
// equiv-conv: FUN_00219870 esi stack
int __cdecl FUN_00219870(Sample* sample, float value) {
    unsigned int mask = (1u << (sample->bits & 31)) - 1u;
    mask |= 1u;
    union { float f; unsigned int u; } bits;
    bits.f = value + 1.0f;
    return sample->base + (bits.u % mask) * 20;
}