// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 25/26, incomplete)
// FUN_00216340 @ 0x00216340
#include "compat/ptr.h"
extern "C" char *strncpy(char *dst, const char *src, unsigned int n);
extern "C" char *strncat(char *dst, const char *src, unsigned int n);
extern "C" char *strcat(char *dst, const char *src);
extern "C" char *strcpy(char *dst, const char *src);
extern "C" unsigned int strlen(const char *s);
extern "C" unsigned int strcspn(const char *s, const char *set);

// Builds a printable chunk id for error messages (Lua luaO_chunkid).
void __cdecl FUN_00216340(char *out, const char *source, int bufflen)
{
    if (*source == '=') {
        strncpy(out, source + 1, bufflen);
        out[bufflen - 1] = '\0';
        return;
    }
    if (*source == '@') {
        source++;
        int room = bufflen - 8;
        hulk_intptr l = strlen(source);
        *out = '\0';
        if (l > room) {
            source += l - room;
            strcat(out, "...");
        }
        strcat(out, source);
        return;
    }
    int len = strcspn(source, "\n");
    int room = bufflen - 17;
    if (len > room)
        len = room;
    strcpy(out, "[string \"");
    if (source[len] != '\0') {
        strncat(out, source, len);
        strcat(out, "...");
    } else {
        strcat(out, source);
    }
    strcat(out, "\"]");
}
