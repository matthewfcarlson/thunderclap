// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ca210 @ 0x001ca210
struct Record {
    unsigned int size;
    unsigned int type;
    unsigned int field8;
    unsigned int fieldC;
    unsigned int value3;
    unsigned int value1;
    unsigned int value2;
    void FUN_001ca210(unsigned int first, unsigned int second, unsigned int third);
};
void Record::FUN_001ca210(unsigned int first, unsigned int second, unsigned int third) {
    size = 0x1c;
    type = 0xf;
    field8 = 0;
    fieldC = 0;
    value3 = third;
    value1 = first;
    value2 = second;
}
