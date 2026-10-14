extern "C" void* memset(void*, int, unsigned int);
struct Obj_f8bb0 {
    void* vptr;
    int data[0x80];
    Obj_f8bb0* ctor(int a);
};
Obj_f8bb0* Obj_f8bb0::ctor(int a) {
    vptr = (void*)a;
    memset(data, 0, 0x80 * 4);
    return this;
}
