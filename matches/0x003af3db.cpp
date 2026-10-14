// cl-flags: /O1
extern void* v0[];
extern void* v1_3af3db[];
extern void* v2_3af3db[];
class O_3af3db {
  public:
    void* vptr;
    int pad;
    void* a;
    void* b;
    void* vptr2;
    O_3af3db() throw();
};
O_3af3db::O_3af3db() throw() {
    a = 0;
    b = 0;
    *(void* volatile*)&vptr2 = v0;
    vptr = v1_3af3db;
    vptr2 = v2_3af3db;
}
