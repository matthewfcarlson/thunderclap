extern "C" void* memset(void*, int, unsigned int);
extern void Copy(void*, unsigned int, const char*, const char*);
class Obj_1cb050 {
  public:
    unsigned int data[21];
    Obj_1cb050* Init(unsigned int a, unsigned int b);
};
Obj_1cb050* Obj_1cb050::Init(unsigned int a, unsigned int b) {
    memset(data, 0, 84);
    data[0] = 0x54;
    data[1] = 0x1e;
    Copy(&data[5], 0x40, "%s", (const char*)a);
    data[4] = b;
    return this;
}
