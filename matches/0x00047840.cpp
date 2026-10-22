void* operator new(unsigned int) throw();
class Owner;
class Closure1_47840 {
    char pad[0x24];

  public:
    Closure1_47840(const char*, Owner*, void (*)()) throw();
};
class Registry_47840 {
  public:
    void FUN_001d3b70(const char*, Closure1_47840*);
    void FUN_00047840(const char* a1, Owner* a2, void (*a3)());
};
void Registry_47840::FUN_00047840(const char* a1, Owner* a2, void (*a3)()) {
    Closure1_47840* e = new Closure1_47840(a1, a2, a3);
    FUN_001d3b70(a1, e);
}