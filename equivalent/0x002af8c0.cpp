// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_002af8c0 @ 0x002af8c0
struct Reader {
    char pad00[0xc];
    char open;
    char pad0d;
    char binary;
    char pad0f[0x11];
    char FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Header_2af8c0 {
    unsigned magic;
    unsigned char b4, b5, b6, b7;
    unsigned w8, wc, w10, w14;
    unsigned short s18, s1a;
    unsigned w1c, w20, w24, w28, w2c, w30;
};

// equiv-conv: FUN_002af8c0 esi edi
void FUN_002af8c0(Header_2af8c0 *h, Reader *r)
{
    unsigned tmp;

    r->FUN_002647e0(&tmp, 1, 4, 1); h->magic = tmp;
    r->FUN_002647e0(&tmp, 1, 1, 1); h->b4 = (unsigned char)tmp;
    r->FUN_002647e0(&tmp, 1, 1, 1); h->b5 = (unsigned char)tmp;
    r->FUN_002647e0(&tmp, 1, 1, 1); h->b6 = (unsigned char)tmp;
    r->FUN_002647e0(&tmp, 1, 1, 1); h->b7 = (unsigned char)tmp;
    r->FUN_002647e0(&tmp, 1, 4, 1); h->w8 = tmp;
    r->FUN_002647e0(&tmp, 1, 4, 1); h->wc = tmp;
    r->FUN_002647e0(&tmp, 1, 4, 1); h->w10 = tmp;
    r->FUN_002647e0(&tmp, 1, 4, 1); h->w14 = tmp;
    r->FUN_002647e0(&tmp, 1, 2, 1); h->s18 = (unsigned short)tmp;
    r->FUN_002647e0(&tmp, 1, 2, 1); h->s1a = (unsigned short)tmp;
    r->FUN_002647e0(&tmp, 1, 4, 1); h->w1c = tmp;
    r->FUN_002647e0(&tmp, 1, 4, 1); h->w20 = tmp;
    r->FUN_002647e0(&tmp, 1, 4, 1); h->w24 = tmp;
    r->FUN_002647e0(&tmp, 1, 4, 1); h->w28 = tmp;
    r->FUN_002647e0(&tmp, 1, 4, 1); h->w2c = tmp;
    r->FUN_002647e0(&tmp, 1, 4, 1); h->w30 = tmp;
}
