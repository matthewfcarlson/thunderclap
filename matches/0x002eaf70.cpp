extern "C" void* memcpy(void*, const void*, unsigned int);
struct Buf {
    char pad[0x28];
    char* data;
    char pad2[4];
    char* a;
    char* b;
};
void __cdecl FUN_002eaf70(Buf* p, const void* src, unsigned int n) {
    memcpy(p->data, src, n);
    p->a = p->b = p->data + n;
}