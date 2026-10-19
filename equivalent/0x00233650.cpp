// STATUS: equivalent (tools/equiv.py level 3: 17050 inputs, branch coverage 37/38, incomplete)
// FUN_00233650 @ 0x00233650
// cl-flags: /GS
#include "decls/data/engine/fight.h"

extern "C" void *memcpy(void *dst, const void *src, unsigned int n);

unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);

class Node {
public:
    char pad0[8];
    unsigned int idLo;
    unsigned int idHi;
    char pad10[4];
    Node *parent;
    char pad18[4];
    Node *firstChild;
    Node *nextSibling;
    Node *FUN_00233580(const char *path);
    Node *FUN_00233650(const char *path);
};

Node *Node::FUN_00233650(const char *path)
{
    struct {
        char name[0x40];
    } f;
    if (path == 0 || *path == 0) {
        return this;
    }
    char sep = *(*(const char**)&DAT_004ca248);
    if (*path == sep) {
        Node *root = this;
        for (Node *p = parent; p != 0; p = p->parent)
            root = p;
        Node *r = 0;
        if (root != 0)
            r = root->FUN_00233580(path);
        return r;
    }
    const char *end = path;
    while (*end != sep && *end != 0)
        end++;
    int len = (int)(end - path);
    if (len > 0) {
        memcpy(f.name, path, len);
    } else {
        len = 0;
    }
    f.name[len] = 0;
    unsigned __int64 hash = FUN_002672f0(f.name, 0);
    unsigned int lo = (unsigned int)hash;
    unsigned int hi = (unsigned int)(hash >> 32);
    if (*end != 0)
        end++;
    Node *r = 0;
    if (lo == DAT_004e5b28 && hi == DAT_004e5b2c) {
        if (parent != 0)
            r = parent->FUN_00233650(end);
    } else if (lo == DAT_004e5b00 && hi == DAT_004e5b04) {
        r = FUN_00233650(end);
    } else {
        for (Node *c = firstChild; c != 0; c = c->nextSibling) {
            if (c->idLo == lo && c->idHi == hi) {
                r = c->FUN_00233650(end);
                break;
            }
        }
    }
    return r;
}
