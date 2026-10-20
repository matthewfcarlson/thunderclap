void* FUN_0008d690(unsigned int);
class Owner;
class Registry_30860 {
  public:
    void FUN_001d3b70(const char*, void*);
    void FUN_00030860(const char* a1, Owner* a2, void (*a3)());
};
class Entry_30860 {
  public:
    Entry_30860(const char*, Owner*, void (*)());
};
inline void* operator new(unsigned int, void* p) throw() {
    return p;
}
void Registry_30860::FUN_00030860(const char* a1, Owner* a2, void (*a3)()) {
    Entry_30860* e = new (FUN_0008d690(0x24)) Entry_30860(a1, a2, a3);
    FUN_001d3b70(a1, e);
}