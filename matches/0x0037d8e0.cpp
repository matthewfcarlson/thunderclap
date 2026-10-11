typedef unsigned int u32;
extern u32 g_first_003a0454;
extern u32 g_second_003a0450;
struct Setter {
    void Set(u32 param_1, u32 param_2);
};
void Setter::Set(u32 param_1, u32 param_2) {
    g_first_003a0454 = param_1;
    g_second_003a0450 = param_2;
}