// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00247570 @ 0x00247570
#include "decls/data/engine/audio.h"

struct TextBuffer {
    char storage[0x48];
    void *FUN_002584d0(void *, void *, unsigned int, unsigned int);
    void FUN_002580e0();
};
struct OutputSink {
    void *slot0;
    void *slot1;
    void (__cdecl *slot2)(OutputSink *, void *, const char *);
};
void __cdecl FUN_00247570(const char *text) {
    if (text) {
        unsigned int length = ((const unsigned int *)text)[-1];
        TextBuffer buffer;
        void *result = buffer.FUN_002584d0(((char*)&DAT_004e5f88), ((char*)&DAT_004e5f90), ((const unsigned int *)text)[-2], length);
        OutputSink *sink = (*(OutputSink**)&DAT_004cc1fc);
        sink->slot2(sink, result, text - length);
        buffer.FUN_002580e0();
    }
}