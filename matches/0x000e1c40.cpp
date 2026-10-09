extern int vtable;
class FEDoPopDialog { public: int vptr; int a; int b; int c; int d; char e; FEDoPopDialog(int); };
FEDoPopDialog::FEDoPopDialog(int x) { b = -1; c = -1; d = x; e = 0; vptr = (int)&vtable; }