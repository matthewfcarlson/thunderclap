extern "C" int __cdecl FUN_002381a0(int index, int value);
int DAT_004caa14[1];
extern "C" int __cdecl FUN_002381a0(int index, int value) {
    int old = DAT_004caa14[index];
    DAT_004caa14[index] = value;
    return old;
}