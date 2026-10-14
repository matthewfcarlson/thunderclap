class Sub_cb080 {
  public:
    void Go();
};
class Owner_cb080 {
  public:
    char pad[0x88];
    Sub_cb080* m;
    void Fn();
};
void Owner_cb080::Fn() {
    if (m)
        m->Go();
}
