extern int __cdecl __vsnprintf(char*, int, const char*, void*);

void FUN_000964a0(char* buffer, int size, const char* format, ...) {
    char* args = (char*)&format + 4;
    int result = __vsnprintf(buffer, size, format, args);
    if (size > 0 && result == -1)
        buffer[size - 1] = 0;
}