extern "C" char DAT_0042986c[];
typedef unsigned int u32_24e460;
extern char g1_24e460, g2;
struct A_24e460 {
    void Init(void*, void*, int, int);
};
extern void Work(void*, u32_24e460);
struct C_24e460 {
    void End();
};
void Target(u32_24e460 param_1) {
    char local[0x48];
    ((A_24e460*)local)->Init(&g2, &g1_24e460, 0x1c, 4);
    *(void**)local = (void*)((int)DAT_0042986c);
    Work(local, param_1);
    ((C_24e460*)local)->End();
}