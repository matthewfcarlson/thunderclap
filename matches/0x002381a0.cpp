extern "C" int __cdecl FUN_002381a0(int index, int value);
int g_data_2381a0[1];
extern "C" int __cdecl FUN_002381a0(int index, int value) {
    int old = g_data_2381a0[index];
    g_data_2381a0[index] = value;
    return old;
}