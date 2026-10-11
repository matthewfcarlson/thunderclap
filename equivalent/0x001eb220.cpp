// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001eb220 @ 0x001eb220
struct Resource {
    void* FUN_001f1270();
};
extern Resource* __cdecl FUN_0008d710(int size, int category);
struct State {
    void* resource;
    unsigned int owner;
    unsigned char mode;
    unsigned char active;
    char padding[2];
    float first;
    float second;
    float third;
    unsigned int count;
    State* FUN_001eb220(unsigned int ownerValue, unsigned int unused, unsigned char modeValue);
};
extern State* DAT_004e36d8;
State* State::FUN_001eb220(unsigned int ownerValue, unsigned int unused, unsigned char modeValue) {
    mode = modeValue;
    DAT_004e36d8 = this;
    active = 0;
    first = 100.0f;
    third = 100.0f;
    second = 100.0f;
    count = 1;
    Resource* allocated = FUN_0008d710(20, 6);
    void* result = 0;
    if (allocated)
        result = allocated->FUN_001f1270();
    resource = result;
    owner = ownerValue;
    return this;
}
