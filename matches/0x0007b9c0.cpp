class Obj_7b9c0 {
  public:
    char pad[0x379c];
    int count;
    void remove(int);
    void target();
};
void Obj_7b9c0::target() {
    while (count > 0)
        remove(0);
}