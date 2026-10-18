// cl-flags: /GS
extern "C" char* __cdecl strchr(const char*, int);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
void __cdecl FUN_000c6bc0(const char* name, const char* ext, int arg);
void __cdecl FUN_000c6d90(const char* path, int arg)
{
    char name[0x20];
    const char* dot = strchr(path, '.');
    int len = dot - path;
    strncpy(name, path, len);
    name[len] = 0;
    FUN_000c6bc0(name, dot + 1, arg);
}
