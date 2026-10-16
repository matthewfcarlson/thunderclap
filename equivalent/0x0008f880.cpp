// STATUS: equivalent (tools/equiv.py level 3: 280 inputs, branch coverage 65/74, incomplete)
// FUN_0008f880 @ 0x0008f880
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

extern "C" int __cdecl strcmp(const char *a, const char *b);
extern "C" long __cdecl atol(const char *s);
extern "C" void *__cdecl memcpy(void *d, const void *s, unsigned int n);
extern double __cdecl FUN_003458c1(const char *s);


void FUN_0008f880(int argc, char **argv)
{
    int i;
    for (i = 1; i < argc; i++) {
        const char *arg = argv[i];
        if (strcmp(arg, "-nocd") == 0) {
            (*(char*)&DAT_0049caac) = 0;
        } else if (strcmp(arg, "-level") == 0) {
            i++;
            (*(char*)&DAT_004de950) = 1;
            (*(char*)&DAT_004dd8d0) = 1;
            if (i < argc) {
                const char *s = argv[i];
                char *d = ((char*)&DAT_004dd890);
                char c;
                do {
                    c = *s++;
                    *d++ = c;
                } while (c != 0);
            }
        } else if (strcmp(arg, "-firewire") == 0) {
            (*(char*)&DAT_004dd83f) = 1;
        } else if (strcmp(arg, "-displaymemoryusage") == 0) {
            DAT_004dd83e = 1;
        } else if (strcmp(arg, "-nosound") == 0) {
        } else if (strcmp(arg, "-english") == 0) {
            memcpy(DAT_0049caa4, "english", 8);
        } else if (strcmp(arg, "-italian") == 0) {
            memcpy(DAT_0049caa4, "italian", 8);
        } else if (strcmp(arg, "-french") == 0) {
            memcpy(DAT_0049caa4, "french", 7);
        } else if (strcmp(arg, "-fakexp") == 0) {
            DAT_004dd838 = 1;
        } else if (strcmp(arg, "-savemissionstats") == 0) {
            (*(char*)&DAT_0049caad) = 1;
        } else if (strcmp(arg, "-pal") == 0) {
            DAT_004dd839 = 1;
        } else if (strcmp(arg, "-drawcode") == 0) {
            DAT_004dd8e7 = 1;
        } else if (strcmp(arg, "-lang") == 0) {
            i++;
            if (i < argc) {
                const char *s = argv[i];
                char *d = ((char*)&DAT_004dd8d4);
                char c;
                do {
                    c = *s++;
                    *d++ = c;
                } while (c != 0);
            }
        } else if (strcmp(arg, "-fmvvol") == 0) {
            i++;
            if (i < argc) {
                DAT_0049cab0 = (float)FUN_003458c1(argv[i]);
            }
        } else if (strcmp(arg, "-difficulty") == 0) {
            i++;
            if (i < argc) {
                (*(long*)&DAT_0049cab4) = atol(argv[i]);
            }
        } else if (strcmp(arg, "-lighthack") == 0) {
            DAT_004dd8e5 = 1;
        } else if (strcmp(arg, "-autotester") == 0) {
            i++;
            (*(char*)&DAT_004dd841) = 1;
            if (i < argc) {
                const char *s = argv[i];
                char *d = ((char*)&DAT_004dd848);
                char c;
                do {
                    c = *s++;
                    *d++ = c;
                } while (c != 0);
            }
        } else if (strcmp(arg, "-nofilenotfound") == 0) {
            DAT_004dd8e6 = 1;
        } else if (strcmp(arg, "-caminvertx") == 0) {
            DAT_004dd83a = 1;
        } else if (strcmp(arg, "-caminverty") == 0) {
            DAT_004dd83b = 1;
        } else if (strcmp(arg, "-caminvert1x") == 0) {
            DAT_004dd83c = 1;
        } else if (strcmp(arg, "-caminvert1y") == 0) {
            DAT_004dd83d = 1;
        } else if (strcmp(arg, "-notintextbible") == 0) {
            (*(char*)&DAT_004dd8e8) = ((*(char*)&DAT_004dd8e8) == 0);
        } else if (strcmp(arg, "-nodpad") == 0) {
            (*(char*)&DAT_0049caae) = 1;
        } else if (strcmp(arg, "-notargeticon") == 0) {
            (*(char*)&DAT_004dd888) = 1;
        } else if (strcmp(arg, "-framerateicon") == 0) {
            (*(char*)&DAT_004dd8e4) = 1;
        }
    }
}
