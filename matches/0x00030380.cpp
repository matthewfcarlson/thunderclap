void* operator new(unsigned int) throw();
class Owner;
class Registry_30380 {
  public:
    void FUN_001d3b70(const char*, void*) throw();
    void FUN_00030380(const char* a1, Owner* a2, void (*a3)());
};
class Entry_30380 {
    char pad[0x24];

  public:
    Entry_30380(const char*, Owner*, void (*)()) throw();
};
void Registry_30380::FUN_00030380(const char* a1, Owner* a2, void (*a3)()) {
    Entry_30380* e = new Entry_30380(a1, a2, a3);
    FUN_001d3b70(a1, e);
}