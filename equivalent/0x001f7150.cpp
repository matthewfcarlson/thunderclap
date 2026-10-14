// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001f7150 @ 0x001f7150
// equiv-map: ??0Name@@QAE@H@Z = 0x0027b0e0
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50

struct Vec3 {
    float x, y, z;
};

struct Name {
    int lo, hi;
    Name(int key) throw();
    ~Name() throw();
};

struct Mat {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022be40(Vec3 *pos);
};

struct Placer {
    void *FUN_00283a40(const Name &name, const Mat &m, float lo, float hi) throw();
};

Placer *FUN_0027f250();

void * __stdcall FUN_001f7150(int key, Vec3 pos, float rx, float ry, float rz)
{
    Mat m;
    m.FUN_0022b980();
    m.FUN_0022bc20(rx * 0.01745329238474369f, ry * 0.01745329238474369f, rz * 0.01745329238474369f);
    m.FUN_0022be40(&pos);
    Placer *placer = FUN_0027f250();
    if (placer == 0)
        return 0;
    Name name(key);
    return placer->FUN_00283a40(name, m, -1.0f, 1.0f);
}
