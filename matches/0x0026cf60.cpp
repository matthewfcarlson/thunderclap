extern "C" int __cdecl Allocate(int, int);
extern "C" int __stdcall Process(int, int, int, int);

int __cdecl FUN_0026cf60(int param_1, int param_2, int param_3) {
    int size = Allocate(0x4a4, 4);
    if (param_1 != 0)
        return Process(1, size + param_1, param_2 - size, param_3);
    return 0;
}