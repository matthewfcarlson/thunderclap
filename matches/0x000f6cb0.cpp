// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 0/0)
// FUN_000f6cb0 @ 0x000f6cb0
// cl-flags: /GS
extern "C" char* __cdecl strchr(const char*, int);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
void __cdecl FUN_000f6af0(char*, char*, unsigned int);
void __cdecl FUN_000f6cb0(char* path, unsigned int arg) {
    struct Frame { char prefix[40];  } frame;
    char* dot = strchr(path, '.');
    unsigned int length = dot - path;
    strncpy(frame.prefix, path, length);
    frame.prefix[length] = 0;
    FUN_000f6af0(frame.prefix, dot + 1, arg);
}