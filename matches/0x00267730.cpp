extern "C" int __cdecl _vsnprintf(char*, unsigned int, const char*, char*);
extern "C" void __cdecl target(char* buf, unsigned int size, const char* fmt, char* args) {
    _vsnprintf(buf, size, fmt, args);
    if (size <= 0)
        return;
    buf[size - 1] = 0;
}