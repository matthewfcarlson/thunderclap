// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001b7360 @ 0x001b7360
struct State { int mode; void FUN_000863e0(int); };
struct Object {
    char pad0[8];
    unsigned char active;
    char pad1[7];
    int value;
    char text[256];
    unsigned char pending;
    char pad2[3];
    State *state;
    void FUN_001b7360(const char *source, int number);
};
void Object::FUN_001b7360(const char *source, int number) {
    if (source && state->mode != 7) {
        value = number;
        pending = 1;
        char *dest = text;
        char c;
        do {
            c = *source++;
            *dest++ = c;
        } while (c);
        state->FUN_000863e0(7);
        active = 1;
    }
}