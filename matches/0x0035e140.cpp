extern unsigned __int64 __cdecl FUN_0027b020(const char*);
extern unsigned int g_first;
extern unsigned int g_second;

void FUN_0035e140() {
    unsigned __int64 result = FUN_0027b020("$MACRO_INSERT");
    g_first = (unsigned int)result;
    g_second = (unsigned int)(result >> 32);
}
