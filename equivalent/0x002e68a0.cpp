// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 12/12)
// FUN_002e68a0 @ 0x002e68a0
#include "decls/data/engine/physics.h"

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
   // "0123456789ABCDEF"
struct png_struct_2e68a0 {
    char pad[0x114];
    unsigned char chunk_name[4];
};

// libpng png_format_buffer: "chunk: message" with unprintable chunk-name bytes written as [XX].
// equiv-conv: FUN_002e68a0 eax ecx edx
void FUN_002e68a0(char* buffer, png_struct_2e68a0* png_ptr, const char* message) {
    int pos = 0;
    for (int i = 0; i < 4; i++) {
        int c = png_ptr->chunk_name[i];
        if (c < 0x29 || c > 0x7a || (c > 0x5a && c < 0x61)) {
            buffer[pos] = '[';
            buffer[pos + 1] = DAT_0042fdd4[(c >> 4) & 0xf];
            buffer[pos + 2] = DAT_0042fdd4[c & 0xf];
            buffer[pos + 3] = ']';
            pos += 4;
        } else {
            buffer[pos++] = (char)c;
        }
    }
    if (message == 0) {
        buffer[pos] = 0;
        return;
    }
    buffer[pos] = ':';
    buffer[pos + 1] = ' ';
    // the original copies with an inline rep movs; a plain forward loop keeps clang from emitting a memcpy call
    {
        char *dst = buffer + pos + 2;
        const char *src = message;
        for (int k = 0; k < 16; k++) { *(unsigned int *)dst = *(const unsigned int *)src; dst += 4; src += 4; } // rep movsd x16
    }
    buffer[pos + 2 + 63] = 0;
}
