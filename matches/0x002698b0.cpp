typedef int(__cdecl* Dummy_2698b0)(void);
extern "C" int __cdecl FUN_002673d0(char*, int);
extern "C" int __cdecl FUN_002698b0(char* path) {
    if (*path == '\\')
        ++path;
    return FUN_002673d0(path, 0);
}
