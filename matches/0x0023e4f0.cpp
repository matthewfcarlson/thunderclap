class Sub_23e4f0 {
  public:
    char pad[0x14];
};

class Obj_23e4f0 {
  public:
    char pad[0x14];
    Sub_23e4f0 sub;
    Sub_23e4f0* GetConditionGroup_0023e4f0();
};

Sub_23e4f0* Obj_23e4f0::GetConditionGroup_0023e4f0() {
    return &sub;
}
