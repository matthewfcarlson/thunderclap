typedef unsigned int u32;
extern u32 g_first;
extern u32 g_second;
struct Setter {
    void Set(u32 param_1, u32 param_2);
};
void Setter::Set(u32 param_1, u32 param_2) {
    g_first = param_1;
    g_second = param_2;
}