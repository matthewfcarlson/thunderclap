// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
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
    double delta = (double)time - (int)times[first];
    if (delta == 0.0f) {
        *result = values[first];
        return;
    }
    int base = values[first];
    int difference = (int)((unsigned int)values[second] - (unsigned int)base);
    int duration = (int)times[second] - (int)times[first];
    int step = (int)(((double)difference / duration) * delta);
    *result = (int)((unsigned int)base + (unsigned int)step);
}
