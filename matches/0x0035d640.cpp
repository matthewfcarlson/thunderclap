extern unsigned long long __cdecl FUN_0027b020(const char*);
extern unsigned int gMemCardName;
extern unsigned int gMemCardControl;
void FUN_0035d640() {
    unsigned long long h = FUN_0027b020("AddMemCardControl");
    gMemCardName = (unsigned int)h;
    gMemCardControl = (unsigned int)(h >> 32);
}
