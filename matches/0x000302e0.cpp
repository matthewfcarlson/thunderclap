typedef unsigned int size_t;
void* FUN_0008d690(unsigned int);
inline void* operator new(size_t n) throw() {
    return FUN_0008d690(n);
}
class Owner;
class Registry_302e0 {
  public:
    void FUN_001d3b70(const char*, void*);
    void FUN_000302e0(const char* a1, Owner* a2, void (*a3)());
};
class Entry_302e0 {
    char pad[0x24];

  public:
    Entry_302e0(const char*, Owner*, void (*)()) throw();
};
void Registry_302e0::FUN_000302e0(const char* a1, Owner* a2, void (*a3)()) {
    FUN_001d3b70(a1, new Entry_302e0(a1, a2, a3));
}