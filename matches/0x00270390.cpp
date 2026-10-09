typedef unsigned int size_t;
extern "C" void * __cdecl memcpy(void *, const void *, size_t);
void * __cdecl FUN_00270390(void *dest, void *param2, const void *src, void *param4, unsigned int count)
{
    memcpy(dest, src, count);
    return dest;
}
