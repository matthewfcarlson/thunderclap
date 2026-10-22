// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cefe0 @ 0x001cefe0
// cl-flags: /GS
struct Closure2_1cefe0 {
    char data[0x24];
    void FUN_001ce7c0(void*, void*, void*);
    void FUN_001d04a0();
};
struct Owner {
    void FUN_001d26d0(void*, Closure2_1cefe0*);
    void FUN_001cefe0(void* a, void* b, void* c);
};
void Owner::FUN_001cefe0(void* a, void* b, void* c) {
    Closure2_1cefe0 temp;
    temp.FUN_001ce7c0(a,b,c);
    FUN_001d26d0(a,&temp);
    temp.FUN_001d04a0();
}