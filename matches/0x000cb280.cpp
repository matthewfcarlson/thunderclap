struct Sub {
    char pad[0x10];
    char flag;
};
class Obj {
  public:
    char pad[0x8c];
    Sub* m8c;
    void Set(unsigned char p);
};
void Obj::Set(unsigned char p) {
    if (m8c) {
        m8c->flag = (p == 1);
    }
}
