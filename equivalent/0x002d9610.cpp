// STATUS: equivalent (tools/equiv.py level 3: 1854 inputs, branch coverage 24/24)
// FUN_002d9610 @ 0x002d9610
struct ImageInfo { unsigned count; unsigned endOffset; unsigned char kind; unsigned char depth; };
void __cdecl FUN_002d9610(const ImageInfo* info, unsigned char* buffer) {
    unsigned n = info->count;
    if (info->kind != 6 && info->kind != 4) return;
    unsigned char* p = buffer + info->endOffset;
    if (info->kind == 6) {
        if (info->depth == 8) {
            while (n--) {
                unsigned char a = p[-1];
                unsigned char b = p[-2];
                p[-1] = b;
                p[-2] = p[-3];
                p[-3] = p[-4];
                p[-4] = a;
                p -= 4;
            }
        } else {
            while (n--) {
                unsigned char a = p[-1];
                unsigned char b = p[-2];
                p[-1] = p[-3];
                p[-2] = p[-4];
                p[-3] = p[-5];
                p[-4] = p[-6];
                p[-5] = p[-7];
                p[-6] = p[-8];
                p[-7] = a;
                p[-8] = b;
                p -= 8;
            }
        }
    } else {
        if (info->depth == 8) {
            while (n--) {
                unsigned char a = p[-1];
                unsigned char b = p[-2];
                p[-1] = b;
                p[-2] = a;
                p -= 2;
            }
        } else {
            while (n--) {
                unsigned char a = p[-1];
                unsigned char b = p[-2];
                p[-1] = p[-3];
                p[-2] = p[-4];
                p[-3] = a;
                p[-4] = b;
                p -= 4;
            }
        }
    }
}
