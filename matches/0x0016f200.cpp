class Obj_16f200 {
  public:
    char pad[0xc];
    void* mField;
    bool SetTimeBegin_0016f200(void* p);
};
bool Obj_16f200::SetTimeBegin_0016f200(void* p) {
    mField = p;
    return true;
}
