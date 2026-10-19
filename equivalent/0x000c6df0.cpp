// STATUS: equivalent (tools/equiv.py level 3: 19983 inputs, branch coverage 0/0)
// FUN_000c6df0 @ 0x000c6df0
// cl-flags: /GS
extern "C" char* __cdecl strchr(const char*, int);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);

void __cdecl FUN_000c6c40(const char* name, const char* ext, int arg);

// Splits "name.ext" at the first '.' and passes both halves on.
void __cdecl FUN_000c6df0(const char* path, int arg)
{
    struct Frame {
        char name[0x20];
    } f;
    const char* dot = strchr(path, '.');
    int len = dot - path;
    strncpy(f.name, path, len);
    f.name[len] = 0;
    FUN_000c6c40(f.name, dot + 1, arg);
}
