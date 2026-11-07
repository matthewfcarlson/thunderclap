// A hash table's constructor (the content loader's two tables): 0x002310a0 allocates its slots and entries.
class Obj {
  public:
    Obj(int a, int b, int c);
    void FUN_002310a0(unsigned int capacity);
    int x0, x4, x8;
    char xc;
    char pad[3];
    int x10, x14;
    void* x18;        // the slots
    void* x1c;        // the entries
    int x20;
};
Obj::Obj(int a, int b, int c) : x0(a), x4(0), x8(0), xc(0), x10(c), x14(b), x18(0), x1c(0), x20(0) {
    FUN_002310a0(a);
}
