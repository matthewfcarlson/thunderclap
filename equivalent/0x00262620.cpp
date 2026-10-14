// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 14/14)
// FUN_00262620 @ 0x00262620
struct Str_262620 {
    char data[12];
    unsigned int FUN_0023f990();
    char* FUN_0023fbb0();
    void FUN_0023fb10(unsigned int newLength);
    Str_262620* FUN_002401f0(Str_262620* out);
    void FUN_00240190(Str_262620* src);
    void FUN_00240060();
};
void __cdecl FUN_00262460(Str_262620* path);

// Normalises a path string in place: '/' becomes '\\', then any trailing separator is removed.
Str_262620* __cdecl FUN_00262620(Str_262620* path) {
    Str_262620 tmp;
    if (path->FUN_0023f990() > 0) {
        for (char* p = path->FUN_0023fbb0(); *p != 0; p++) {
            if (*p == '/')
                *p = '\\';
        }
    }
    FUN_00262460(path);
    unsigned int len = path->FUN_0023f990();
    if (len > 0) {
        char* p = path->FUN_0023fbb0();
        char last = p[len - 1];
        if (last == '\\' || last == '/') {
            p[len - 1] = 0;
            path->FUN_0023fb10(len - 1);
        }
    }
    path->FUN_00240190(path->FUN_002401f0(&tmp));
    tmp.FUN_00240060();
    return path;
}
