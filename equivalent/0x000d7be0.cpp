// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000d7be0 @ 0x000d7be0
struct Object {
    char unused[8];
    unsigned int first;
    unsigned int second;
    unsigned int third;
    unsigned int fourth;
    unsigned int zero1;
    unsigned int zero2;
    unsigned int zero3;
    unsigned int sentinel;
    unsigned int last;
    void FUN_000d7be0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e);
};
void Object::FUN_000d7be0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e) {
    first = a;
    second = b;
    third = c;
    fourth = d;
    zero1 = 0;
    zero2 = 0;
    zero3 = 0;
    sentinel = 0xffffffff;
    last = e;
}