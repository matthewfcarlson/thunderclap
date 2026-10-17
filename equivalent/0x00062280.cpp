// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00062280 @ 0x00062280
extern float DAT_003f3ef4;
struct Angles {
    char pad[0x38];
    float x, y, z;
    void FUN_00062280(float *out);
};
void Angles::FUN_00062280(float *out) {
    out[0] = x * DAT_003f3ef4;
    out[1] = y * DAT_003f3ef4;
    out[2] = z * DAT_003f3ef4;
}
