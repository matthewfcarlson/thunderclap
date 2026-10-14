extern int gData_24c3b0[];
int FUN_0024c3b0(unsigned int* param_1, int param_2) {
    return ((*param_1 >> 4) & 0x1f) * gData_24c3b0[((int)(*param_1 << 28) >> 28) * 6] * param_2;
}