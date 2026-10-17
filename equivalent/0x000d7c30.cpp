// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000d7c30 @ 0x000d7c30
struct Object {
    char reserved[8];
    unsigned int state0;
    unsigned int state1;
    unsigned int state2;
    unsigned int state3;
    unsigned int value0;
    unsigned int value1;
    unsigned int value2;
    unsigned int value3;
    unsigned int value4;
    unsigned int value5;
    void FUN_000d7c30(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f);
};

void Object::FUN_000d7c30(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f)
{
    state0 = 0;
    state1 = 0;
    value0 = a;
    value1 = b;
    state2 = 0;
    value2 = c;
    state3 = 0xffffffff;
    value3 = d;
    value4 = e;
    value5 = f;
}