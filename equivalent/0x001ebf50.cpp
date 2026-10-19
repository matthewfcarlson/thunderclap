// STATUS: equivalent (tools/equiv.py level 3: 18575 inputs, branch coverage 6/6)
// FUN_001ebf50 @ 0x001ebf50
// cl-flags: /GS
// FUN_001ebf50 @ 0x001ebf50
extern "C" char *__cdecl strcat(char *dst, const char *src);
extern "C" void *__cdecl memcpy(void *dst, const void *src, unsigned int n);
extern "C" void *__cdecl memset(void *dst, int c, unsigned int n);


// Builds the debug name "crush_<name>" in a local buffer (the result is never used).
// The /GS cookie sits directly above the buffer, as in the original.
void __stdcall FUN_001ebf50(const char *name, int unused) {
    struct Frame {
        char buf[70];
        char pad[2];
    } f;
    if (name != 0) {
        memcpy(f.buf, "crush_", 7);
        memset(f.buf + 7, 0, 63);
        strcat(f.buf, name);
    }
}
