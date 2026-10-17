// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c0b80 @ 0x000c0b80
extern unsigned DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned);
struct ClosureBase {
    virtual void invoke();
    char data[28];
    const char *second;
    ClosureBase(const char *, const char *);
    void FUN_001d04a0();
};
struct Closure7 : ClosureBase {
    virtual void invoke();
    Closure7(const char *first, const char *third) : ClosureBase(first, third) {}
};
struct Manager {
    void FUN_001d26d0(const char *, ClosureBase *);
    void FUN_000c0b80(const char *, const char *, const char *);
};
void Manager::FUN_000c0b80(const char *first, const char *second, const char *third)
{
    volatile unsigned cookie = DAT_004d9968;
    Closure7 closure(first, third);
    closure.second = second;
    FUN_001d26d0(first, &closure);
    closure.FUN_001d04a0();
    __security_check_cookie(cookie);
}