extern "C" void* memset(void*, int, unsigned int);
struct Elem_1e11d0 {
    void Init(int);
};
struct Obj_1e11d0 {
    char pad[0x1ed68];
    void Dec();
    void Df();
    void Target();
};
void Obj_1e11d0::Target() {
    memset((char*)this + 8, 0, 0x600);
    char* s = (char*)this + 0x1ed68;
    int i;
    for (i = 0; i < 16; ++i) {
        ((Elem_1e11d0*)(s - 8))->Init(0);
        *(int*)s = 0;
        *(int*)(s + 4) = 0;
        *(int*)(s + 8) = 0xff;
        s += 0x18;
    }
    Dec();
    Df();
    *(int*)((char*)this + 0x1e82c) = 0;
    *(int*)((char*)this + 0x1e828) = 0;
    char* t = (char*)this + 0x1e840;
    int j, k;
    for (j = 0; j < 4; ++j)
        for (k = 0; k < 32; ++k) {
            ((Elem_1e11d0*)t)->Init(0);
            t += 8;
        }
}