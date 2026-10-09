typedef unsigned int U32;
extern void* MakeTemp(int);
extern void* AllocTemp(void*);
extern void* AllocMem(int);

void Target(U32** out, U32* src, int count) {
    void* p = MakeTemp(0);
    p = AllocTemp(p);
    *out = (U32*)AllocMem(count * 4 + 4);
    int i;
    for (i = 0; i < count; ++i)
        (*out)[i] = src[i];
    (*out)[count] = 0;
    AllocTemp(p);
}