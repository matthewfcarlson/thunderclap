struct Obj { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(int); };
extern Obj** FUN_00266f50(void*, int);
extern char DAT_00527f40;
void FUN_00267090(int param_1) {
    Obj** p = FUN_00266f50(&DAT_00527f40, param_1);
    (*p)->f4(param_1);
}