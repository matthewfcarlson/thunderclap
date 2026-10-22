typedef unsigned int size_t;
void* operator new(size_t) throw();
class Owner;
class Registry_31000 {
  public:
    void FUN_001d3b70(const char*, void*);
    void FUN_00031000(const char* a1, Owner* a2, void (*a3)());
};
class Closure2_31000 {
    char pad[36];

  public:
    Closure2_31000(const char*, Owner*, void (*)()) throw();
};
void Registry_31000::FUN_00031000(const char* a1, Owner* a2, void (*a3)()) {
    Closure2_31000* e = new Closure2_31000(a1, a2, a3);
    FUN_001d3b70(a1, e);
}