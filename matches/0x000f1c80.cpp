class Sub { public: void init(); };
class Sub2 { public: void init(); };
void thunk_FUN_00267090(void*);
class FEControl { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); };
class TextTable : public FEControl {
public:
  TextTable* vfunc_2(unsigned char p);
  char pad[0x495c - 4];
};
TextTable* TextTable::vfunc_2(unsigned char p) {
  *(unsigned long*)this = 0x40c6a4;
  char* q = (char*)this + 0x495c;
  for (int i = 0x200; i != 0; --i) {
    q -= 0x24;
    ((Sub*)q)->init();
  }
  *(unsigned long*)this = 0x40c42c;
  ((Sub2*)this)->init();
  if (p & 1) thunk_FUN_00267090(this);
  return this;
}