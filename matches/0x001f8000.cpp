void* FUN_0008d690(unsigned int) throw();
class Owner;
class Closure2_1f8000 {
  public:
    static void* operator new(unsigned int n) throw() { return FUN_0008d690(n); }
    Closure2_1f8000(const char*, Owner*, void (*)()) throw();
    char pad[0x24];
};
class Registry_1f8000 {
  public:
    void FUN_001d3b70(const char*, Closure2_1f8000*);
    void FUN_001f8000(const char* a1, Owner* a2, void (*a3)());
};
void Registry_1f8000::FUN_001f8000(const char* a1, Owner* a2, void (*a3)()) {
    Closure2_1f8000* e = new Closure2_1f8000(a1, a2, a3);
    FUN_001d3b70(a1, e);
}