class Sub_caf30 {
  public:
    void Target();
};
class Obj_caf30 {
  public:
    char pad[0x88];
    Sub_caf30* m88;
    void Target();
};
void Obj_caf30::Target() {
    if (m88)
        m88->Target();
}
