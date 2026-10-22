void* operator new(unsigned int) throw();
class Owner;
class Closure1_311b0 {
    char pad[0x24];

  public:
    Closure1_311b0(const char*, Owner*, void (*)()) throw();
};
class Registry_311b0 {
  public:
    void FUN_001d3b70(const char*, void*);
    void FUN_000311b0(const char* a1, Owner* a2, void (*a3)());
};
void Registry_311b0::FUN_000311b0(const char* a1, Owner* a2, void (*a3)()) {
    FUN_001d3b70(a1, new Closure1_311b0(a1, a2, a3));
}