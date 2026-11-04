class Obj_1653a0 {
  public:
    char pad[0x14];
    void* mValue;
    bool SetType_001653a0(void* p);
};
bool Obj_1653a0::SetType_001653a0(void* p) {
    mValue = p;
    return true;
}