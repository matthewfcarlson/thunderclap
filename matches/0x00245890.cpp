int FUN_00245890(int param_1, int param_2) {
    int value = 0;
    int place = 1;
    char* p = (char*)(param_1 + 1);
    char* q = (char*)(param_1 + param_2 - 1);
    while (q >= p) {
        value += (*q - 0x30) * place;
        place *= 10;
        --q;
    }
    return -value;
}