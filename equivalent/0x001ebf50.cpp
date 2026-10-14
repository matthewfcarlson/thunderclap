// STATUS: equivalent (tools/equiv.py level 3: 464 inputs, branch coverage 6/6)
// FUN_001ebf50 @ 0x001ebf50
extern "C" char *__cdecl strcat(char *dst, const char *src);
extern "C" void __fastcall __security_check_cookie(unsigned int cookie);

extern unsigned int DAT_004d9968;

// Builds the debug name "crush_<name>" in a local buffer (the result is never used).
void __stdcall FUN_001ebf50(const char *name, int unused) {
    volatile unsigned int cookie = DAT_004d9968;
    if (name != 0) {
        char buf[70] = "crush_";
        strcat(buf, name);
    }
    __security_check_cookie(cookie);
}
