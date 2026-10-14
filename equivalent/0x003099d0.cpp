// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_003099d0 @ 0x003099d0
struct Sub_3099d0 {
    char data[0x1c];
    void FUN_002fcb80(float scale);
};

struct Source_3099d0 {
    char pad[0x0c];
    float value;
};

struct Holder_3099d0 {
    char pad[0x18];
    Source_3099d0 *source;
};

struct Anim_3099d0 {
    char pad00[0x18];
    Holder_3099d0 *holder;
    char pad1c[0x30 - 0x1c];
    float rate;
    char pad34[4];
    float current;
    float length;
    float inverse;
    char pad44[4];
    Sub_3099d0 subA;
    Sub_3099d0 subB;
    char pad80[0xf0 - 0x80];
    float weight;
    void FUN_003099d0();
};

void Anim_3099d0::FUN_003099d0()
{
    if (length > 0.0f) {
        float previous = current;
        float ratio = (current = holder->source->value * rate) / previous;
        inverse = 1.0f / (length = ratio * length);
        weight = ratio * weight;
        subA.FUN_002fcb80(ratio);
        subB.FUN_002fcb80(ratio);
    }
}
