// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001f7150 @ 0x001f7150
// equiv-map: ??0Name@@QAE@H@Z = 0x0027b0e0
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50

struct Vec3_1f7150 {
    float x, y, z;
};

struct Name {
    int lo, hi;
    Name(int key) throw();
    ~Name() throw();
};

struct Mat_1f7150 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022be40(Vec3_1f7150 *pos);
};

struct Placer_1f7150 {
    void *FUN_00283a40(const Name &name, const Mat_1f7150 &m, float lo, float hi) throw();
};

Placer_1f7150 *FUN_0027f250();

void * __stdcall FUN_001f7150(int key, Vec3_1f7150 pos, float rx, float ry, float rz)
{
    Mat_1f7150 m;
    m.FUN_0022b980();
    m.FUN_0022bc20(rx * 0.01745329238474369f, ry * 0.01745329238474369f, rz * 0.01745329238474369f);
    m.FUN_0022be40(&pos);
    Placer_1f7150 *placer = FUN_0027f250();
    if (placer == 0)
        return 0;
    Name name(key);
    return placer->FUN_00283a40(name, m, -1.0f, 1.0f);
}
