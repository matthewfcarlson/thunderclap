typedef unsigned int u32;
extern char g1, g2;
struct A { void Init(void*, void*, int, int); };
extern void Work(void*, u32);
struct C { void End(); };
void Target(u32 param_1) {
    char local[0x48];
    ((A*)local)->Init(&g2, &g1, 0x1c, 4);
    *(void**)local = (void*)0x42986c;
    Work(local, param_1);
    ((C*)local)->End();
}