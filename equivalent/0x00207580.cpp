// STATUS: equivalent (tools/equiv.py level 3: 18876 inputs, branch coverage 45/46, incomplete)
// FUN_00207580 @ 0x00207580
// cl-flags: /GS
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

extern "C" int __cdecl _sprintf(char *, const char *, ...);
extern int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);

struct Node {
    char pad0[0x56];
    short key;
};

struct Pool_207580 {
    Node *FUN_001c7f10(int id);
};

struct Holder_207580 {
    char pad0[4];
    Pool_207580 *pool;
};
Holder_207580 *__cdecl FUN_001c3d90();

struct Slot3c {
    int f0;
    char used;
    char name[0x33];
    int f38;
};

struct Handle_207580 {
    void FUN_00263e90();
};

struct Thing_207580 {
    void FUN_002660a0(int v);
};

class MapLoader {
public:
    char pad0[4];
    char str1[0x20];        // 4
    char str2[0x20];        // 0x24
    int f44;
    Slot3c slots[22];       // 0x48 (20 + 2)
    int keys[2];            // 0x570
    char pad578[0xaec - 0x578];
    Handle_207580 *handle;         // 0xaec
    char padaf0[2];
    char pending;           // 0xaf2
    void FUN_00207150();
    int FUN_00204c10(int v);
    void FUN_00207080(int v);
    Handle_207580 *FUN_00203e90(char *path, int a, int b, char *slot, int c, int d, int e);
    Thing_207580 *FUN_00203db0(int key);
    void FUN_002067d0(int id, int v);
    bool FUN_00207580(int a1, bool a2);
};

bool MapLoader::FUN_00207580(int a1, bool a2)
{
    struct Frame {
        int key;
        Node *node;
        char name[0x40];
        char path[0x100];
    } f;

    char *slot = 0;
    int arg1_ = a1;
    f.node = FUN_001c3d90()->pool->FUN_001c7f10(arg1_);
    if (f.node == 0) {
        return false;
    }
    for (;;) {
        f.key = f.node->key;
        int j = 0;
        while (j < 2 && keys[j] != f.key)
            j++;
        int ref;
        if (j >= 2) {
            FUN_000964a0(f.path, 0x100, "art/locations/%s/%s_district_%d.p3d", str1, str2, f.key);
            _sprintf(f.name, "%s_district_%d", str2, f.key);
            FUN_00207150();
            if ((*(char*)((char*)&DAT_004c91d8 + 1)) != 0) {
                int s = 0;
                while (s < 2 && slots[20 + s].used != 0)
                    s++;
                slot = s < 2 ? (char *)&slots[20 + s] : 0;
                char *d = slot + 5;
                char *src = f.name;
                char c;
                do {
                    c = *src;
                    *d = c;
                    d++;
                    src++;
                } while (c != 0);
            }
            ref = f44;
            pending = 1;
        } else {
            FUN_000964a0(f.path, 0x100, "art/locations/%s/%s_r%03d.p3d", str1, str2, a1);
            _sprintf(f.name, "%s_r%03d", str2, a1);
            if ((*(char*)&DAT_004c91d8) != 0) {
                int s = 0;
                while (s < 0x14 && slots[s].used != 0)
                    s++;
                slot = s < 0x14 ? (char *)&slots[s] : 0;
                char *d = slot + 5;
                char *src = f.name;
                char c;
                do {
                    c = *src;
                    *d = c;
                    d++;
                    src++;
                } while (c != 0);
            }
            if (pending != 0) {
                ref = f44;
            } else {
                ref = 0;
                if ((*(char*)((char*)&DAT_004c91d8 + 1)) != 0) {
                    int k2 = f.node->key;
                    int m = 0;
                    while (m < 2 && keys[m] != k2)
                        m++;
                    if (m < 2)
                        ref = slots[20 + m].f38;
                }
            }
        }
        if (!a2 && (*(char*)&DAT_004e5a50) == 0) {
            handle = FUN_00203e90(f.path, 1, 0, slot, 0, ref, 0xb);
            return true;
        }
        if (pending == 0) {
            int n = FUN_00204c10(0);
            if (n > 0)
                FUN_00207080(n);
        }
        handle = FUN_00203e90(f.path, 0, 1, slot, 0, ref, 0xb);
        handle->FUN_00263e90();
        bool wasPending = pending != 0;
        handle = 0;
        if (!wasPending) {
            FUN_002067d0(a1, 1);
            return true;
        }
        pending = 0;
        int q = 0;
        while (q < 2 && keys[q] != 0)
            q++;
        if (q < 2)
            keys[q] = f.key;
        int arg2_ = f44;
        FUN_00203db0(f.key)->FUN_002660a0(arg2_);
    }
}
