extern "C" int __cdecl __vsnprintf(char*, unsigned int, const char*, char*);
extern "C" void FUN_00267760(char* buffer, unsigned int size, const char* format) {
    __vsnprintf(buffer, size, format, (char*)&format + 4);
    if (!(size <= 0U))
        buffer[size - 1] = 0;
}