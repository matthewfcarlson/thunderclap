extern int count;
extern void* ptr;
extern void __cdecl release(void*);
void FUN_0027b1d0() {
    if (--count == 0) {
        if (ptr)
            release(ptr);
        ptr = 0;
    }
}