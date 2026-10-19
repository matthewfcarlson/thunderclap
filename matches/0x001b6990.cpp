class Obj {
  public:
    Obj() throw();
    char data[0x80];
};
void* __cdecl operator new(unsigned int) throw();
extern Obj* volatile gObj;
Obj* __cdecl FUN_001b6990() {
    Obj* p = gObj;
    if (!p)
        gObj = p = new Obj;
    return p;
}