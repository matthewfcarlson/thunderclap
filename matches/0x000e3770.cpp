struct Obj { char pad0[0x40]; char pad40[4]; unsigned int c; unsigned char b; char pad49[3]; unsigned int d; };
struct Owner { char pad0[0x4c]; unsigned int value4c; char pad50[0xf8]; unsigned int value148; char pad14c[0x1d88-0x14c]; Obj* volatile item; void Set(Obj*); };
void Owner::Set(Obj* p) {
  item = p;
  if (p) {
    ((unsigned char*)p)[0x40] = 1;
    ((unsigned char*)item)[0x48] = 1;
    unsigned int a = value148;
    ((unsigned int*)(((char*)item) + 0x44))[0] = a;
    unsigned int b = value4c;
    ((unsigned int*)(((char*)item) + 0x4c))[0] = b;
  }
}
