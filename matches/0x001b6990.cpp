class Obj {
  public:
    Obj() throw();
    char data[0x80];
};
void* __cdecl operator new(unsigned int) throw();
extern Obj* volatile gObj;
void __cdecl FUN_001b6990() {
    if (!gObj)
        gObj = new Obj;
}