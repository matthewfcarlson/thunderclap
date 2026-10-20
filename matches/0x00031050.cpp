void* operator new(unsigned int) throw();
class Owner;
class Registry_31050 {
  public:
    void FUN_001d3b70(const char*, void*);
    void FUN_00031050(const char* a1, Owner* a2, void (*a3)());
};
class Entry_31050 {
  public:
    char pad[0x24];
    Entry_31050(const char*, Owner*, void (*)()) throw();
};
void Registry_31050::FUN_00031050(const char* a1, Owner* a2, void (*a3)()) {
    Entry_31050* e = new Entry_31050(a1, a2, a3);
    FUN_001d3b70(a1, e);
}