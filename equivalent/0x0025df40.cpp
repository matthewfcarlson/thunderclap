// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0025df40 @ 0x0025df40
void __cdecl FUN_0025dcb0(int* p);

class Scheduler {
public:
    float one;              // 0x00
    int f04;
    Scheduler* list0;       // 0x08
    Scheduler* list0a;      // 0x0c (sentinel)
    Scheduler* list0b;      // 0x10
    Scheduler* list0c;      // 0x14
    int count0;             // 0x18
    Scheduler* list1;       // 0x1c
    Scheduler* list1a;      // 0x20 (sentinel)
    Scheduler* list1b;      // 0x24
    Scheduler* list1c;      // 0x28
    int count1;             // 0x2c
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    char b54;
    char pad55[3];
    int f58;
    char b5c;
    Scheduler* FUN_0025df40(int a, int b, int c);
    void FUN_0025db30();
};

Scheduler* Scheduler::FUN_0025df40(int a, int b, int c)
{
    f04 = a;
    one = 1.0f;
    count0 = 0;
    Scheduler* n0 = (Scheduler*)&list0a;
    list0a = n0;
    list0b = n0;
    list0c = n0;
    list0 = n0;
    count1 = 0;
    Scheduler* n1 = (Scheduler*)&list1a;
    list1a = n1;
    list1b = n1;
    list1c = n1;
    list1 = n1;
    f30 = b;
    f38 = 0;
    f3c = c;
    f40 = 0;
    f44 = 0;
    f4c = 0;
    f50 = 0;
    f58 = 0;
    f34 = 0;
    b54 = (char)0xff;
    b5c = 0;
    f48 = 0;
    FUN_0025dcb0(&f40);
    f48 = 0;
    FUN_0025db30();
    return this;
}
