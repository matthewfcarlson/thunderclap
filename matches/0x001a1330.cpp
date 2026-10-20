// Same code shape as 0x0011c270 (propagated; names are from that function)
void __cdecl Cleanup(int);
class LuaCondition_1a1330 {
  public:
    int a, b;
    virtual ~LuaCondition_1a1330();
    int d;
    virtual void hulk_slot_F(); void F();
};
LuaCondition_1a1330::~LuaCondition_1a1330() {
    Cleanup(d);
    F();
}