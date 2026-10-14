// STATUS: equivalent (tools/equiv.py level 3: 1439 inputs, branch coverage 4/4)
// FUN_0021b1c0 @ 0x0021b1c0
struct Buffer_21b1c0 {
    char* data;
    unsigned int n;
    unsigned int size;
};
struct Zio_21b1c0 {
    unsigned int n;
    const unsigned char* p;
};
struct LexState_21b1c0 {
    int current;
    char pad4[0x1c];
    void* L;
    Zio_21b1c0* z;
    Buffer_21b1c0* buff;
};
char* __cdecl FUN_0021add0(void* L, char* block, unsigned int oldsize, unsigned int newsize);
int __cdecl FUN_0021a550(Zio_21b1c0* z);
// equiv-conv: FUN_0021b1c0 edi
void FUN_0021b1c0(LexState_21b1c0* ls) {
    Buffer_21b1c0* b = ls->buff;
    if (b->n + 1 > b->size) {
        b->data = FUN_0021add0(ls->L, b->data, b->size, b->size * 2 + 0x20);
        b->size = b->size * 2 + 0x20;
    }
    b->data[b->n] = (char)ls->current;
    b->n++;
    if (ls->z->n-- > 0)
        ls->current = *ls->z->p++;
    else
        ls->current = FUN_0021a550(ls->z);
}
