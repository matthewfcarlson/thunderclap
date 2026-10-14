class Sub {
  public:
    void Target();
};
class Obj {
  public:
    char pad[0x88];
    Sub* m88;
    void Target();
};
void Obj::Target() {
    if (m88)
        m88->Target();
}
