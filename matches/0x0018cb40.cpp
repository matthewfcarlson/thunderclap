class Obj_18cb40 {
  public:
    char pad[0x1c];
    void* m1c;
    bool Set(void* p);
};
bool Obj_18cb40::Set(void* p) {
    m1c = p;
    return true;
}