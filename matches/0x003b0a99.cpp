// cl-flags: /O1
extern void* v_3b0a99[];
void __stdcall Free(void*, unsigned);
class G_3b0a99 {
  public:
    void* vptr;
    void Un(void*) throw();
};
extern G_3b0a99 g_3b0a99;
class O_3b0a99 {
  public:
    void* vptr;
    O_3b0a99* f2(unsigned char flags);
};
O_3b0a99* O_3b0a99::f2(unsigned char flags) {
    vptr = v_3b0a99;
    g_3b0a99.Un(this);
    if (flags & 1)
        Free(this, 0x24870000);
    return this;
}
