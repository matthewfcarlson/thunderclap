class Obj_215410 {
  public:
    char p0[0x14];
    int m14;
    char p18[0x0c];
    int m24;
    int m28;
    unsigned short m2c;
};
extern int __cdecl Grow(Obj_215410*, int, unsigned int, unsigned int);
extern "C" void __cdecl FUN_00215410(void * self, unsigned int count) {
    unsigned short c = (unsigned short)count;
    int old = ((Obj_215410 *)self)->m28;
    int n = Grow(((Obj_215410 *)self), old, ((unsigned int)((Obj_215410 *)self)->m2c) << 4, count << 4);
    ((Obj_215410 *)self)->m2c = c;
    ((Obj_215410 *)self)->m28 = n;
    ((Obj_215410 *)self)->m14 = ((((Obj_215410 *)self)->m14 - old) >> 4) * 16 + n;
    ((Obj_215410 *)self)->m24 = (((unsigned int)c) << 4) + n;
}