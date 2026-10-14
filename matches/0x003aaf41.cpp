// cl-flags: /O1
extern void* vt_3aaf41[];
class O_3aaf41 {
  public:
    void* vptr;
    int a[4];
    O_3aaf41() throw();
};
O_3aaf41::O_3aaf41() throw() {
    *(void* volatile*)&vptr = vt_3aaf41;
    for (int i = 0; i <= 3; i++)
        a[i] = i;
}
