class Sub {
  public:
    void Go();
};
class Owner {
  public:
    char pad[0x88];
    Sub* m;
    void Fn();
};
void Owner::Fn() {
    if (m)
        m->Go();
}
