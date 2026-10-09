// Same code shape as 0x001ca090 (propagated; names are from that function)
extern const char checkpoint[];
class Thing {
  public:
    bool ready();
    void mark(const char*, int);
    void finish();
};
Thing* GetThing();
class Owner {
  public:
    char pad[0x14];
    int value;
    bool run();
};
bool Owner::run() {
    Thing* t = GetThing();
    if (!t)
        return false;
    if (!t->ready())
        return false;
    t->mark(checkpoint, value);
    t->finish();
    return true;
}