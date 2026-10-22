extern const char strA[], strB[], strC[];
char __cdecl GetFlag(const char*);
class Function_1b1660 {
  public:
    virtual void f();
    Function_1b1660(void*, int);
    char pad[20];
};
class Function2 : public Function_1b1660 {
  public:
    virtual void g();
    Function2(void*, void*);
    char flag18[4];
    void* target;
};
Function2::Function2(void* a, void* b) : Function_1b1660(a, 2) {
    target = b;
    flag18[0] = GetFlag(strA);
    ((char*)this)[0x10] = GetFlag(strB);
    ((char*)this)[0x11] = GetFlag(strC);
}
