extern const char k_string[];
extern "C" unsigned long long __cdecl FUN_0027b020(const char* s);
extern unsigned int g_result_lo;
extern unsigned int g_result_hi;

void __cdecl FUN_0035e040() {
    unsigned long long r = FUN_0027b020(k_string);
    g_result_lo = (unsigned int)r;
    g_result_hi = (unsigned int)(r >> 32);
}
