class Obj_61f10 {
  public:
    char pad[0x38];
    void* m38;
    bool Set(void* v);
};
bool Obj_61f10::Set(void* v) {
    m38 = v;
    return true;
}
