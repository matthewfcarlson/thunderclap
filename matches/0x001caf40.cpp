// Same code shape as 0x001ca090 (propagated; names are from that function)
extern const char checkpoint[];
class Thing_1caf40 {
  public:
    bool ready();
    void mark(const char*, int);
    void finish();
};
Thing_1caf40* GetThing();
class Owner_1caf40 {
  public:
    char pad[0x14];
    int value;
    bool run();
};
bool Owner_1caf40::run() {
    Thing_1caf40* t = GetThing();
    if (!t)
        return false;
    if (!t->ready())
        return false;
    t->mark(checkpoint, value);
    t->finish();
    return true;
}