extern "C" char* __cdecl getText(char*);
extern "C" int __cdecl strcmp(const char*, const char*);
extern char yesStr[];
extern char noStr[];
char* __cdecl target(char* p) {
    char* a = getText(p);
    char* b = getText(p);
    return strcmp(a, b) ? yesStr : noStr;
}