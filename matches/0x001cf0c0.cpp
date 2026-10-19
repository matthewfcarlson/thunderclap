// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cf0c0 @ 0x001cf0c0
// cl-flags: /GS
struct Local {
    char data[36];
    Local(int, int, int);
    void FUN_001d04a0();
};
struct Actor {
    void FUN_001d26d0(int, Local*);
    void FUN_001cf0c0(int a, int b, int c);
};
void Actor::FUN_001cf0c0(int a, int b, int c)
{
    Local value(a, b, c);
    FUN_001d26d0(a, &value);
    value.FUN_001d04a0();
}