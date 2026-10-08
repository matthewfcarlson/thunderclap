typedef unsigned short u16;
void FUN_002f40f0(u16*, int, int, u16);
void FUN_002f4350(u16* param_1, u16* param_2) {
    int count = ((char*)param_2 - (char*)param_1) >> 1;
    int i = count / 2;
    while (i > 0) {
        --i;
        u16 v = param_1[i];
        FUN_002f40f0(param_1, i, count, v);
    }
}