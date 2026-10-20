void* FUN_0008d690(unsigned int);
inline void* operator new(unsigned int, void* p) throw() {
    return p;
}
class Owner;
class Registry_1cc2c0 {
  public:
    void FUN_001d3b70(const char*, void*);
    void FUN_001cc2c0(const char* a1, Owner* a2, void (*a3)());
};
class Entry_1cc2c0 {
  public:
    Entry_1cc2c0(const char*, Owner*, void (*)());
};
void Registry_1cc2c0::FUN_001cc2c0(const char* a1, Owner* a2, void (*a3)()) {
    Entry_1cc2c0* e = new (FUN_0008d690(0x24)) Entry_1cc2c0(a1, a2, a3);
    FUN_001d3b70(a1, e);
}