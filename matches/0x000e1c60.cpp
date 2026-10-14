// Same code shape as 0x000e1c40 (propagated; names are from that function)
extern int vtable_e1c60;
class FEDoPopDialog {
  public:
    int vptr;
    int a;
    int b;
    int c;
    int d;
    char e;
    FEDoPopDialog(int);
};
FEDoPopDialog::FEDoPopDialog(int x) {
    b = -1;
    c = -1;
    d = x;
    e = 0;
    vptr = (int)&vtable_e1c60;
}