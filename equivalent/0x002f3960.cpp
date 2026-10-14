// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002f3960 @ 0x002f3960
extern "C" int __cdecl FUN_0034483c();

class Quantizer {
public:
    char pad0[0x44];
    float *scale;   // 0x44: offsets at [9..11], scales at [15..17]
    void FUN_002f3960(unsigned short *out, const float *in);
};

// Quantizes three floats (last component first) into 16-bit values.
void Quantizer::FUN_002f3960(unsigned short *out, const float *in)
{
    for (int i = 2; i >= 0; i--) {
        float v = (in[i] - scale[9 + i]) * scale[15 + i];
        if (v <= 0.0f)
            out[i] = 0;
        else if (v > 65535.0f)
            out[i] = 0xffff;
        else
            out[i] = (unsigned short)(int)v;
    }
}
