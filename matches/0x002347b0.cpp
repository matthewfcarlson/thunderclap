typedef unsigned int U32_2347b0;
extern void* MakeTemp(int);
extern void* AllocTemp(void*);
extern void* AllocMem(int);

void Target(U32_2347b0** out, U32_2347b0* src, int count) {
    void* p = MakeTemp(0);
    p = AllocTemp(p);
    *out = (U32_2347b0*)AllocMem(count * 4 + 4);
    int i;
    for (i = 0; i < count; ++i)
        (*out)[i] = src[i];
    (*out)[count] = 0;
    AllocTemp(p);
}