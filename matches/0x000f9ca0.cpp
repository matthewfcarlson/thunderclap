typedef unsigned long long U64_f9ca0;
class CScriptToken {
  public:
    virtual void vfunc_0();
    virtual U64_f9ca0 vfunc_1();
    virtual void vfunc_2();
};
class CTokenHashed : public CScriptToken {
  public:
    char pad[12];
    virtual U64_f9ca0 vfunc_1();
};
U64_f9ca0 CTokenHashed::vfunc_1() {
    return *(U64_f9ca0*)((char*)this + 0x10);
}