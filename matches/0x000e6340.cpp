class Other { public: virtual void f0(); virtual void f1(); virtual void f2x(); virtual bool f3(int, int); };
class FEThingsBase {
public:
 virtual void f0(); virtual void f1(); virtual void f2x(); virtual bool vfunc_2(int, int); virtual void f4();
 char p0[0x175c-4]; Other *a; Other *b;
 char p1[0x2100-0x1764]; char flag;
 char p2[0x2218-0x2101]; Other *c;
};
bool FEThingsBase::vfunc_2(int x, int index) {
 if (*((char*)this + 0x2100 + index)) return true;
 if (c) return c->f3(x,index);
 if (b) return b->f3(x,index);
 if (a) return a->f3(x,index);
 return false;
}