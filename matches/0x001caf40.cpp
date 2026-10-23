// Same code shape as 0x001ca090 (propagated; names are from that function)
extern const char DAT_00421cb0[];
class Thing_1caf40 {
  public:
    bool ready();
    void mark(const char*, int);
    void finish();
};
Thing_1caf40* FUN_001d4c90();
class Owner_1caf40 {
  public:
    char pad[0x14];
    int value;
    bool run();
};
bool Owner_1caf40::run() {
    Thing_1caf40* t = FUN_001d4c90();
    if (!t)
        return false;
    if (!t->ready())
        return false;
    t->mark(DAT_00421cb0, value);
    t->finish();
    return true;
}