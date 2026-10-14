// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001eb220 @ 0x001eb220
struct Resource_1eb220 {
    void* FUN_001f1270();
};
extern Resource_1eb220* __cdecl FUN_0008d710(int size, int category);
struct State_1eb220 {
    void* resource;
    unsigned int owner;
    unsigned char mode;
    unsigned char active;
    char padding[2];
    float first;
    float second;
    float third;
    unsigned int count;
    State_1eb220* FUN_001eb220(unsigned int ownerValue, unsigned int unused, unsigned char modeValue);
};
extern State_1eb220* DAT_004e36d8;
State_1eb220* State_1eb220::FUN_001eb220(unsigned int ownerValue, unsigned int unused, unsigned char modeValue) {
    mode = modeValue;
    DAT_004e36d8 = this;
    active = 0;
    first = 100.0f;
    third = 100.0f;
    second = 100.0f;
    count = 1;
    Resource_1eb220* allocated = FUN_0008d710(20, 6);
    void* result = 0;
    if (allocated)
        result = allocated->FUN_001f1270();
    resource = result;
    owner = ownerValue;
    return this;
}
