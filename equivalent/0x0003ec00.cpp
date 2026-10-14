// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0003ec00 @ 0x0003ec00
struct Progress_3ec00 {
    char pad00[0x1e58];
    float value;          // 0x1e58
    int key;              // 0x1e5c
    float Consume(int k);
};

float Progress_3ec00::Consume(int k)
{
    float v = value;
    if (k != key) {
        value = 0.0f;
        return 0.0f;
    }
    if (v >= 0.0f && v <= 1.0f) {
        value = 0.0f;
        return v;
    }
    value = 0.0f;
    if (v > 1.0f)
        return 1.0f;
    return 0.0f;
}
