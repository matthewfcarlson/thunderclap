extern unsigned int FUN_00246f50(unsigned int, const char*, unsigned int);
const char g_fmt[] = "%s ";
extern "C" unsigned char FUN_0024eff0(unsigned int* stream, unsigned int text) {
    FUN_00246f50(*stream, g_fmt, text);
    return 0;
}