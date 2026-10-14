struct Sub_cb280 {
    char pad[0x10];
    char flag;
};
class Obj_cb280 {
  public:
    char pad[0x8c];
    Sub_cb280* m8c;
    void Set(unsigned char p);
};
void Obj_cb280::Set(unsigned char p) {
    if (m8c) {
        m8c->flag = (p == 1);
    }
}
