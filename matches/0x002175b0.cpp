extern const float g_zero;
extern float* FUN_00219e50(int a, int b);

float* FUN_002175b0(int param_1, int* param_2, int param_3) {
    int iVar1;
    switch (*param_2) {
    case 5:
        iVar1 = ((int*)param_2[1])[2];
        break;
    case 7:
        iVar1 = ((int*)param_2[1])[2];
        break;
    default:
        return (float*)&g_zero;
    }
    if (iVar1 != 0) {
        int* arr = *(int**)((char*)param_1 + 0x10);
        int elem = *(int*)((char*)arr + param_3 * 4 + 0x74);
        return FUN_00219e50(iVar1, elem);
    }
    return (float*)&g_zero;
}
