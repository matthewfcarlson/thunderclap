// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_003285d0 @ 0x003285d0
extern float DAT_00555b68;
extern float DAT_00555b6c;
extern float DAT_00555b70;
extern float DAT_00555b74;
extern float DAT_00555b78;
extern float DAT_00555b7c;
extern float DAT_00555b80;
extern unsigned int DAT_00555b84;
struct AccumulatorSource {
    char padding[0x80];
    float x, y, z, w;
    unsigned char red, green, blue, alpha;
    unsigned char enabled;
    void FUN_003285d0(unsigned int unused);
};
void AccumulatorSource::FUN_003285d0(unsigned int unused) {
    if (enabled) {
        ++DAT_00555b84;
        DAT_00555b68 = DAT_00555b68 + x;
        DAT_00555b6c = DAT_00555b6c + y;
        DAT_00555b70 = DAT_00555b70 + z;
        DAT_00555b74 = DAT_00555b74 + w;
        DAT_00555b78 = float(blue) + DAT_00555b78;
        DAT_00555b7c = float(green) + DAT_00555b7c;
        DAT_00555b80 = float(red) + DAT_00555b80;
    }
}
