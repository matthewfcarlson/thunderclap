class Reader {
  public:
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
};
namespace fight {
class BinReader : public Reader {
  public:
    char pad[0x18 - sizeof(void*)];
    unsigned long long vfunc_15();
};
unsigned long long BinReader::vfunc_15() {
    return *(unsigned long long*)((char*)this + 0x18);
}
} // namespace fight