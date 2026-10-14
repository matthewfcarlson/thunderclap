struct Vec {
    int x, y, z;
};
extern void FUN_002273d0(Vec*, int, int, Vec);
void FUN_002274a0(Vec* first, Vec* last, Vec* out, Vec value) {
    *out = *first;
    FUN_002273d0(first, 0, last - first, value);
}