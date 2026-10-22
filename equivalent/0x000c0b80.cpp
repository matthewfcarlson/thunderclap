// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_000c0b80 @ 0x000c0b80
// cl-flags: /GS
struct Method7_c0b80 {
    virtual void invoke();
    char data[28];
    const char *second;
    Method7_c0b80(const char *, const char *);
    void FUN_001d04a0();
};
struct Closure7 : Method7_c0b80 {
    virtual void invoke();
    Closure7(const char *first, const char *third) : Method7_c0b80(first, third) {}
};
struct Manager {
    void FUN_001d26d0(const char *, Method7_c0b80 *);
    void FUN_000c0b80(const char *, const char *, const char *);
};
void Manager::FUN_000c0b80(const char *first, const char *second, const char *third)
{
    Closure7 closure(first, third);
    closure.second = second;
    FUN_001d26d0(first, &closure);
    closure.FUN_001d04a0();
}