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
void __cdecl Target(Obj_215410* self, unsigned int count) {
    unsigned short c = (unsigned short)count;
    int old = self->m28;
    int n = Grow(self, old, ((unsigned int)self->m2c) << 4, count << 4);
    self->m2c = c;
    self->m28 = n;
    self->m14 = ((self->m14 - old) >> 4) * 16 + n;
    self->m24 = (((unsigned int)c) << 4) + n;
}