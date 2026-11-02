// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_002dd760 @ 0x002dd760
struct Stream {
    void FUN_002647e0(void *dest, unsigned count, unsigned size, int flag);
};

struct Header_2dd760 {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char pad3;
    unsigned short w4;
    unsigned short w6;
    unsigned char b8;
    unsigned char pad9;
    unsigned short wA;
    unsigned short wC;
    unsigned short wE;
    unsigned short w10;
    unsigned char b12;
    unsigned char b13;
};

// equiv-conv: FUN_002dd760 esi edi
extern "C" void FUN_002dd760(void *out, void *s)
{
    unsigned int tmp;

    ((Stream *)s)->FUN_002647e0(&tmp, 1, 1, 1);
    ((Header_2dd760 *)out)->b0 = *(unsigned char *)&tmp;
    ((Stream *)s)->FUN_002647e0(&tmp, 1, 1, 1);
    ((Header_2dd760 *)out)->b1 = *(unsigned char *)&tmp;
    ((Stream *)s)->FUN_002647e0(&tmp, 1, 1, 1);
    ((Header_2dd760 *)out)->b2 = *(unsigned char *)&tmp;
    ((Stream *)s)->FUN_002647e0(&tmp, 1, 2, 1);
    ((Header_2dd760 *)out)->w4 = *(unsigned short *)&tmp;
    ((Stream *)s)->FUN_002647e0(&tmp, 1, 2, 1);
    ((Header_2dd760 *)out)->w6 = *(unsigned short *)&tmp;
    ((Stream *)s)->FUN_002647e0(&tmp, 1, 1, 1);
    ((Header_2dd760 *)out)->b8 = *(unsigned char *)&tmp;
    ((Stream *)s)->FUN_002647e0(&tmp, 1, 2, 1);
    ((Header_2dd760 *)out)->wA = *(unsigned short *)&tmp;
    ((Stream *)s)->FUN_002647e0(&tmp, 1, 2, 1);
    ((Header_2dd760 *)out)->wC = *(unsigned short *)&tmp;
    ((Stream *)s)->FUN_002647e0(&tmp, 1, 2, 1);
    ((Header_2dd760 *)out)->wE = *(unsigned short *)&tmp;
    ((Stream *)s)->FUN_002647e0(&tmp, 1, 2, 1);
    ((Header_2dd760 *)out)->w10 = *(unsigned short *)&tmp;
    ((Stream *)s)->FUN_002647e0(&tmp, 1, 1, 1);
    ((Header_2dd760 *)out)->b12 = *(unsigned char *)&tmp;
    ((Stream *)s)->FUN_002647e0(&tmp, 1, 1, 1);
    ((Header_2dd760 *)out)->b13 = *(unsigned char *)&tmp;
}
