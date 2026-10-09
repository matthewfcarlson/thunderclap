extern "C" int __cdecl FUN_002381a0(int index, int value);
int g_data[1];
extern "C" int __cdecl FUN_002381a0(int index, int value) {
    int old = g_data[index];
    g_data[index] = value;
    return old;
}