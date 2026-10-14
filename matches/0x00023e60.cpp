class Obj_23e60 {
  public:
    char pad[0x80];
    void Helper();
    void Target();
};
void Obj_23e60::Target() {
    ((Obj_23e60*)((char*)this + 0x80))->Helper();
}
