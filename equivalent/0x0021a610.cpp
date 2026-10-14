// STATUS: equivalent (tools/equiv.py level 3: 152 inputs, branch coverage 13/14, incomplete)
// FUN_0021a610 @ 0x0021a610
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

struct ZIO {
    unsigned int n;                     // bytes left in the current buffer
    const unsigned char *p;             // read position
    const unsigned char *(__cdecl *reader)(void *L, void *data, unsigned int *size);
    void *data;
    void *L;
};

// luaZ_read: copies n bytes out of the stream, returns the number of bytes missing
unsigned int __cdecl FUN_0021a610(ZIO *z, void *b, unsigned int n)
{
    while (n != 0) {
        if (z->n == 0) {
            unsigned int size;
            const unsigned char *buff = z->reader(z->L, z->data, &size);
            if (buff == 0 || size == 0)
                return n;
            z->n = size - 1;
            z->p = buff;
            int c = *z->p++;
            if (c == -1)
                return n;
            z->n++;
            z->p--;
        }
        unsigned int m = (n <= z->n) ? n : z->n;
        memcpy(b, z->p, m);
        z->n -= m;
        z->p += m;
        b = (char *)b + m;
        n -= m;
    }
    return 0;
}
