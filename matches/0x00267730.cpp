extern "C" int __cdecl _vsnprintf(char*, unsigned int, const char*, char*);
extern "C" int __cdecl FUN_00267730(char* buf, unsigned int size, const char* fmt, char* args) {
    int n = _vsnprintf(buf, size, fmt, args);
    if (size <= 0)
        return n;
    buf[size - 1] = 0;
    return n;
}