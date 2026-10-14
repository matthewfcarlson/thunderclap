// Same code shape as 0x001ca090 (propagated; names are from that function)
extern const char checkpoint[];
class Thing_1cadb0 {
  public:
    bool ready();
    void mark(const char*, int);
    void finish();
};
Thing_1cadb0* GetThing();
class Owner_1cadb0 {
  public:
    char pad[0x14];
    int value;
    bool run();
};
bool Owner_1cadb0::run() {
    Thing_1cadb0* t = GetThing();
    if (!t)
        return false;
    if (!t->ready())
        return false;
    t->mark(checkpoint, value);
    t->finish();
    return true;
}