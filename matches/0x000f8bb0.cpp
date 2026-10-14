extern "C" void* memset(void*, int, unsigned int);
struct Obj {
    void* vptr;
    int data[0x80];
    Obj* ctor(int a);
};
Obj* Obj::ctor(int a) {
    vptr = (void*)a;
    memset(data, 0, 0x80 * 4);
    return this;
}
