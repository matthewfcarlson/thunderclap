class Obj { public: virtual void a(); virtual void release(); };
class Inner { public: void dispose(); };
class A { public: char p0[4]; unsigned char a,b; char p1[0x20]; short value; char p2[4]; void *ptr2c; Obj *obj30; char p3[4]; Inner *ptr38; void close(); };
extern void fvalue(int); extern void fptr(void *);
void A::close() { if (ptr38) { ptr38->dispose(); ptr38=0; } if (obj30) fvalue((int)value); if (obj30) { obj30->release(); obj30=0; } if (ptr2c) { fptr(ptr2c); ptr2c=0; } a=0; b=0; value=0; }
