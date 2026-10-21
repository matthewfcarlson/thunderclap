// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 6/6)
// FUN_0028a0b0 @ 0x0028a0b0
struct Track {
    int unknown;
    int interpolate;
    char padding[12];
    short* times;
    int* values;
    bool FUN_00289f80(float time, int* first, int* second);
    void sample(float time, int* result);
};
void Track::sample(float time, int* result) {
    int first, second;
    bool found = FUN_00289f80(time, &first, &second);
    if (!found || !interpolate) {
        *result = values[first];
        return;
    }
    double delta = (double)time - (int)(__int64)times[first];
    if (delta == 0.0f) {
        *result = values[first];
        return;
    }
    int base = values[first];
    int difference = (int)(__int64)((unsigned int)(__int64)values[second] - (unsigned int)(__int64)base);
    int duration = (int)(__int64)times[second] - (int)(__int64)times[first];
    int step = (int)(__int64)(((double)difference / duration) * delta);
    *result = (int)(__int64)((unsigned int)(__int64)base + (unsigned int)(__int64)step);
}
