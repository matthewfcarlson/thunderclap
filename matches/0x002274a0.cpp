struct Vec_2274a0 {
    int x, y, z;
};
extern void FUN_002273d0(Vec_2274a0*, int, int, Vec_2274a0);
void FUN_002274a0(Vec_2274a0* first, Vec_2274a0* last, Vec_2274a0* out, Vec_2274a0 value) {
    *out = *first;
    FUN_002273d0(first, 0, last - first, value);
}