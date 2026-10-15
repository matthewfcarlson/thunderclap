void FUN_002a1e60(int, int, int, int, int);
void FUN_002a2090(int first, int last, int arg) {
    int count = (last - first) >> 2;
    int i = count / 2;
    while (i > 0) {
        --i;
        FUN_002a1e60(first, i, count, ((int*)first)[i], arg);
    }
}