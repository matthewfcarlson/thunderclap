extern "C" unsigned int __cdecl tick();
struct Timer {
    float scale;
    unsigned int last;
    float Delta();
};
float Timer::Delta() {
    unsigned int t = tick();
    unsigned int d = t - last;
    float result = (float)d * scale;
    last = t;
    return result;
}