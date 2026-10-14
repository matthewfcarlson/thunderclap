// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000e2860 @ 0x000e2860
struct SubObject_e2860 {
    char data[0x24];
    void FUN_000f7930();
};
struct FEObject {
    virtual void slot0();
    unsigned int baseFields[4]; // 04
    unsigned int field14;
    SubObject_e2860 sub; // 18
    int field3c;
    unsigned char field40;
    char pad41[3];
    int field44;
    unsigned char field48;
    char pad49[3];
    unsigned int color;
    unsigned int field50;
    float scale54, scale58, scale5c;
    unsigned int field60, field64;
    unsigned char field68;
    char pad69[7];
    unsigned int field70;
    unsigned char field74;
    char pad75[3];
    unsigned int field78, field7c, field80;
    char pad84[4];
    unsigned int field88, field8c, field90, field94;
    unsigned char field98;
    char pad99[11];
    unsigned int fielda4;
    char pada8[4];
    unsigned int fieldac;
    unsigned int block[12];
    unsigned int fielde0;
    FEObject(int unused);
};
FEObject::FEObject(int unused) {
    baseFields[0] = baseFields[1] = baseFields[2] = baseFields[3] = 0;
    sub.FUN_000f7930();
    fielde0 = 0;
    field3c = field44 = -1;
    field14 = 0;
    fielda4 = 0;
    field74 = 1;
    field98 = 0;
    field90 = field94 = 0;
    field40 = field48 = 0;
    color = 0xff000000;
    field50 = 0;
    scale54 = scale58 = scale5c = 1.0f;
    field60 = field64 = 0;
    field68 = 0;
    field88 = field8c = fieldac = 0;
    for (int i = 0; i < 12; ++i) block[i] = 0;
    field70 = 2;
    field80 = field7c = field78 = 0;
}
