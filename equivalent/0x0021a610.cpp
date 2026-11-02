// STATUS: equivalent (tools/equiv.py level 3: 152 inputs, branch coverage 13/14, incomplete)
// FUN_0021a610 @ 0x0021a610
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

struct ZIO_21a610 {
    unsigned int n;                     // bytes left in the current buffer
    const unsigned char *p;             // read position
    const unsigned char *(__cdecl *reader)(void *L, void *data, unsigned int *size);
    void *data;
    void *L;
};

// luaZ_read: copies n bytes out of the stream, returns the number of bytes missing
extern "C" unsigned int __cdecl FUN_0021a610(void *z, void *b, unsigned int n)
{
    while (n != 0) {
        if (((ZIO_21a610 *)z)->n == 0) {
            unsigned int size;
            const unsigned char *buff = ((ZIO_21a610 *)z)->reader(((ZIO_21a610 *)z)->L, ((ZIO_21a610 *)z)->data, &size);
            if (buff == 0 || size == 0)
                return n;
            ((ZIO_21a610 *)z)->n = size - 1;
            ((ZIO_21a610 *)z)->p = buff;
            int c = *((ZIO_21a610 *)z)->p++;
            if (c == -1)
                return n;
            ((ZIO_21a610 *)z)->n++;
            ((ZIO_21a610 *)z)->p--;
        }
        unsigned int m = (n <= ((ZIO_21a610 *)z)->n) ? n : ((ZIO_21a610 *)z)->n;
        memcpy(b, ((ZIO_21a610 *)z)->p, m);
        ((ZIO_21a610 *)z)->n -= m;
        ((ZIO_21a610 *)z)->p += m;
        b = (char *)b + m;
        n -= m;
    }
    return 0;
}
