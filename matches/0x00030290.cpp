void* operator new(unsigned int) throw();
class Owner;
class Registry_30290 {
  public:
    void FUN_001d3b70(const char*, void*);
    void FUN_00030290(const char* a1, Owner* a2, void (*a3)());
};
class Entry_30290 {
  public:
    Entry_30290(const char*, Owner*, void (*)()) throw();
    char bytes[0x24];
};
void Registry_30290::FUN_00030290(const char* a1, Owner* a2, void (*a3)()) {
    Entry_30290* e = new Entry_30290(a1, a2, a3);
    FUN_001d3b70(a1, e);
}