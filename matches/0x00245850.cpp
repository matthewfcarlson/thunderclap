int FUN_00245850(char *param_1, int param_2)
{
    int value = 0;
    int place = 1;
    char *p;
    for (p = param_1 + param_2 - 1; p >= param_1; --p) {
        value += (*p - 0x30) * place;
        place *= 10;
    }
    return value;
}