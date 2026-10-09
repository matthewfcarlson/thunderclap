typedef unsigned int uint;
typedef unsigned short ushort;
extern void* FUN_00247610(const char*, const char*, int, int);
extern const char str1[];
extern const char str2[];
extern "C" void* memcpy(void*, const void*, unsigned int);
void FUN_0023fa40(int* out, char* src, uint n, int len) {
    char* p = (char*)FUN_00247610(str1, str2, len + 9, 4);
    *out = (int)(p + 8);
    *(ushort*)(*out - 2) = (ushort)len;
    *(ushort*)(*out - 4) = 1;
    memcpy((void*)*out, src, n);
    ((char*)*out)[n] = 0;
}