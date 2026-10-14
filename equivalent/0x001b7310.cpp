// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 6/6)
// FUN_001b7310 @ 0x001b7310
struct State_1b7310 {
    int value;
    void FUN_000863e0(int value);
};
struct Object {
    char pad0[8];
    unsigned char active;
    char pad9[7];
    unsigned int parameter;
    char text[256];
    unsigned char flag;
    char pad115[3];
    State_1b7310* state;
    void update(const char* source, unsigned int parameterValue, unsigned char flagValue);
};
void Object::update(const char* source, unsigned int parameterValue, unsigned char flagValue) {
    if (source && state->value != 7) {
        flag = flagValue;
        parameter = parameterValue;
        char* destination = text;
        char c;
        do {
            c = *source++;
            *destination++ = c;
        } while (c != 0);
        state->FUN_000863e0(7);
        active = 1;
    }
}
