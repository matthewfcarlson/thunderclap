// STATUS: equivalent (tools/equiv.py level 3: 18573 inputs, branch coverage 6/6)
// FUN_001ebf50 @ 0x001ebf50
// FUN_001ebf50 @ 0x001ebf50
extern "C" char *__cdecl strcat(char *dst, const char *src);
extern "C" void *__cdecl memcpy(void *dst, const void *src, unsigned int n);
extern "C" void *__cdecl memset(void *dst, int c, unsigned int n);
extern "C" void __fastcall __security_check_cookie(unsigned int cookie);

extern unsigned int DAT_004d9968;

// Builds the debug name "crush_<name>" in a local buffer (the result is never used).
// The /GS cookie sits directly above the buffer, as in the original.
void __stdcall FUN_001ebf50(const char *name, int unused) {
    struct Frame {
        char buf[70];
        char pad[2];
        unsigned int cookie;
    } f;
    f.cookie = DAT_004d9968;
    if (name != 0) {
        memcpy(f.buf, "crush_", 7);
        memset(f.buf + 7, 0, 63);
        strcat(f.buf, name);
    }
    __security_check_cookie(f.cookie);
}
