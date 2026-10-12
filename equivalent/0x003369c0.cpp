// STATUS: equivalent (tools/equiv.py level 3: 179 inputs, branch coverage 68/83, incomplete)
// FUN_003369c0 @ 0x003369c0
struct Entry {
    char pad0[8];
    int type;               // 0x08
    unsigned int *desc;     // 0x0c
    char pad10[8];
};

struct Header {
    char pad0[4];
    char name[0x40];        // 0x04
    int count;              // 0x44
    Entry entries[1];       // 0x48
    Entry *FUN_00337090(int index);
};

struct Pool {
    char *FUN_00337d60(unsigned int size, unsigned int align);
};

extern Pool DAT_0055dbb0;
extern unsigned int DAT_0055dbb4;

unsigned int __cdecl FUN_00335270(unsigned int v);

#define SWAP(v) (swap ? FUN_00335270(v) : (v))
#define REBASE(v) ((v) ? (v) - DAT_0055dbb4 : 0)

class Relocator {
public:
    char pad0[4];
    Header *hdr;            // 0x04
    unsigned int *arr;      // 0x08
    unsigned int data2;     // 0x0c
    void FUN_003369c0(char swap);
};

void Relocator::FUN_003369c0(char swap)
{
    int count = hdr->count;
    int i;
    for (i = 0; i < count; i++) {
        Entry *e = hdr->FUN_00337090(i);
        unsigned int *p;
        unsigned int v;
        switch (e->type) {
        case 1:
        case 2:
        case 3:
            p = &arr[i];
            v = SWAP(arr[i]);
            *p = v;
            break;
        case 5:
        case 7: {
            unsigned int *q = (unsigned int *)arr[i];
            v = SWAP(*q);
            *q = v;
            q++;
            v = SWAP(*q);
            *q = v;
            goto rebase;
        }
        case 6:
        case 8: {
            unsigned int *q = (unsigned int *)arr[i];
            v = SWAP(*q);
            *q = v;
            q++;
            v = SWAP(*q);
            *q = v;
            q++;
            v = SWAP(*q);
            *q = v;
            goto rebase;
        }
        case 4:
        case 10:
        rebase:
            v = arr[i];
            arr[i] = REBASE(v);
            p = &arr[i];
            v = SWAP(arr[i]);
            *p = v;
            break;
        case 9: {
            unsigned int *q = (unsigned int *)arr[i];
            if (q == 0)
                break;
            unsigned int *desc = e->desc;
            int n = (int)*q;
            v = SWAP(n);
            *q = v;
            q++;
            if (n > 0) {
                for (; n != 0; n--) {
                    switch (*desc) {
                    case 1:
                    case 2:
                    case 3:
                        v = SWAP(*q);
                        *q = v;
                        q++;
                        break;
                    case 4:
                    case 10:
                        v = *q;
                        v = REBASE(v);
                        *q = v;
                        v = SWAP(v);
                        *q = v;
                        break;
                    case 5:
                    case 7:
                        v = SWAP(*q);
                        *q = v;
                        q++;
                        v = SWAP(*q);
                        *q = v;
                        q++;
                        break;
                    case 6:
                    case 8:
                        v = SWAP(*q);
                        *q = v;
                        q++;
                        v = SWAP(*q);
                        *q = v;
                        q++;
                        v = SWAP(*q);
                        *q = v;
                        q++;
                        break;
                    default:
                        break;
                    }
                }
            }
            v = arr[i];
            arr[i] = REBASE(v);
            p = &arr[i];
            v = SWAP(arr[i]);
            *p = v;
            break;
        }
        default:
            break;
        }
    }

    unsigned int a = (unsigned int)arr;
    a = REBASE(a);
    arr = (unsigned int *)a;
    a = SWAP(a);
    arr = (unsigned int *)a;

    unsigned int b = data2;
    b = REBASE(b);
    data2 = b;
    b = SWAP(b);
    data2 = b;

    const char *s = hdr->name;
    const char *t = s;
    while (*t++ != 0) {
    }
    unsigned int len = (unsigned int)(t - s - 1);
    char *dst = DAT_0055dbb0.FUN_00337d60(len + 1, 4);
    char *d = dst;
    const char *r = hdr->name;
    char c;
    do {
        c = *r++;
        *d++ = c;
    } while (c != 0);
    unsigned int off = (unsigned int)dst;
    off = REBASE(off);
    if (swap)
        off = FUN_00335270(off);
    unsigned int *out = (unsigned int *)DAT_0055dbb0.FUN_00337d60(0xc, 4);
    out[0] = (unsigned int)arr;
    out[1] = data2;
    out[2] = off;
}
