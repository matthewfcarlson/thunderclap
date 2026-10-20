typedef unsigned __int64 U64;
U64 __cdecl FUN_002672f0(int, int, int);
int __cdecl FUN_002673a0(int, int);
struct Base {
    int field4, field8, fieldC;
    Base(int c) : field4(0), field8(0), fieldC(c) {}
};
struct Pair {
    int low, high;
    Pair() : low(0), high(0) {}
    inline void Set(U64 v) {
        high = (int)(v >> 32);
        low = (int)v;
    }
};
struct CSoundCommand_PlayInterruptEvent : Base {
    virtual void dummy();
    Pair pair;
    int field18;
    CSoundCommand_PlayInterruptEvent(int a, int b, int c);
};
CSoundCommand_PlayInterruptEvent::CSoundCommand_PlayInterruptEvent(int a, int b, int c) : Base(c) {
    U64 value = FUN_002672f0(a, 0, 0);
    pair.Set(value);
    field18 = FUN_002673a0(b, 0);
}