typedef unsigned int u32_24f870;
struct Arg_24f870 {
    char pad[0x3c];
    u32_24f870 value;
};
struct Result_24f870 {
    char pad[0x44];
    u32_24f870 link;
};
extern Result_24f870* __cdecl FUN_0024a940(u32_24f870, void*);
class SeqActionChannelSends {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(Arg_24f870*);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad[4];
    void* data;
    u32_24f870 state;
};
void SeqActionChannelSends::vfunc_1(Arg_24f870* arg) {
    u32_24f870 val = arg->value;
    Result_24f870* r = FUN_0024a940(val, (char*)data + 0x108);
    r->link = (u32_24f870)((char*)data + 8);
    state = 0;
}