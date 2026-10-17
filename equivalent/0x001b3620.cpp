// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001b3620 @ 0x001b3620
extern float DAT_003f32e0;
extern float DAT_0041d97c;
extern float DAT_004e18d0[];
int __stdcall FUN_001b3250(float value);

struct SampleTable {
    char padding[12];
    int row;
    char padding2[12];
    float limit;
    float FUN_001b3620(float value);
};

float SampleTable::FUN_001b3620(float value) {
    int index = row;
    if (index < 0)
        return DAT_003f32e0;
    if (value < DAT_0041d97c)
        value = 0.02f;
    if (value >= limit)
        return DAT_003f32e0;
    int column = FUN_001b3250(value);
    return DAT_004e18d0[column + index * 45];
}