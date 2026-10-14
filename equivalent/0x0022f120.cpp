// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_0022f120 @ 0x0022f120
struct OutputState {
    char data[0x80];
    void FUN_0022e930(void* output, int divisor);
    void FUN_0022eb00(void* output);
};
struct Animator_22f120 {
    char padding[0x88];
    OutputState state;
    unsigned char looping;
    char pad109[7];
    unsigned int count;
    char pad114[8];
    int tick;
    int divisor;
    bool FUN_0022ef20(int flag, float position);
    void* FUN_0022f120(void* output);
};
void* Animator_22f120::FUN_0022f120(void* output) {
    int next = (int)((unsigned int)tick + 1u);
    float position = (float)((double)next / (double)divisor);
    unsigned char loop = looping;
    tick = next;
    if (loop && (double)position == (double)count) {
        tick = 0;
        position = 0.0f;
    } else if (position < 0.0f) {
        position = 0.0f;
    }
    unsigned int limit = loop ? count : count - 3u;
    if ((double)limit < (double)position)
        position = (float)limit;
    if (FUN_0022ef20(1, position))
        state.FUN_0022e930(output, divisor);
    else
        state.FUN_0022eb00(output);
    return output;
}
