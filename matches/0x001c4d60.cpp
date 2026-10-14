extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct X_1c4d60 {
    char pad[0x30];
    unsigned int data[16];
    void f(unsigned int*);
};
void X_1c4d60::f(unsigned int* p) {
    memcpy(data, p, 64);
}