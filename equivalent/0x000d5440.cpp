// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000d5440 @ 0x000d5440
class Gauge_d5440 {
public:
    char pad000[0x22c];
    float level0;           // 0x22c
    float rate0;            // 0x230
    char pad234[0xc];
    int hold0;              // 0x240
    char pad244[4];
    char enabled0;          // 0x248
    char pad249[0x468 - 0x249];
    float level1;           // 0x468
    float rate1;            // 0x46c
    char pad470[0xc];
    int hold1;              // 0x47c
    char pad480[4];
    char enabled1;          // 0x484
    void FUN_000d5440();
};

void Gauge_d5440::FUN_000d5440()
{
    if (enabled0 && hold0 == 0) {
        double v = (0.15f + rate0) + 0.1f;
        level0 = (v > level0) ? (float)v : level0;
    }
    if (enabled1 && hold1 == 0) {
        double v = (0.15f + rate1) + 0.1f;
        level1 = (v > level1) ? (float)v : level1;
    }
}
