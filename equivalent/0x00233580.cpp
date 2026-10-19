// STATUS: equivalent (tools/equiv.py level 3: 18200 inputs, branch coverage 22/22)
// FUN_00233580 @ 0x00233580
// cl-flags: /GS
// FUN_00233580 @ 0x00233580
#include "decls/data/engine/fight.h"

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

struct HashKey {
    int lo, hi;
};

HashKey __cdecl FUN_002672f0(const char* s, int a, int b);

class PathNode {
public:
    char pad0[8];
    HashKey key;            // 0x8
    char pad10[0x1c - 0x10];
    PathNode* firstChild;   // 0x1c
    PathNode* nextSibling;  // 0x20
    PathNode* FUN_00233580(const char* path);
};

// Finds the descendant named by a delimiter-separated path.
PathNode* PathNode::FUN_00233580(const char* path)
{
    // The /GS cookie sits directly above the buffer, as in the original.
    struct Frame {
        char buf[0x40];
    } f;
    char* buf = f.buf;
    char delim = *(*(char**)&DAT_004ca248);
    if (*path == delim)
        path++;
    const char* end = path;
    while (*end != 0 && *end != delim)
        end++;
    int len = end - path;
    int n = 0;
    if (len > 0) {
        memcpy(buf, path, len);
        n = len;
    }
    buf[n] = 0;
    HashKey k = FUN_002672f0(buf, 0, 0);
    PathNode* result = 0;
    if (k.lo == key.lo && k.hi == key.hi) {
        if (*end == 0) {
            result = this;
        } else {
            for (PathNode* c = firstChild; c != 0; c = c->nextSibling) {
                result = c->FUN_00233580(end);
                if (result != 0)
                    break;
            }
        }
    }
    return result;
}
