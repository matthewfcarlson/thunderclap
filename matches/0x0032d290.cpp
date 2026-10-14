class Obj_32d290 {
  public:
    char pad[0x84];
    bool mValid;
    void Set(void* p);
};
void Obj_32d290::Set(void* p) {
    mValid = (p != 0);
}
