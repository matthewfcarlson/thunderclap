class Inner {
  public:
    void Set(int, bool);
};
class Owner {
  public:
    char pad[0x4c];
    Inner* inner;
};
class Target {
  public:
    char pad[4];
    Owner* owner;
    void Run(void* p);
};
void Target::Run(void* p) {
    if (owner && owner->inner)
        owner->inner->Set(2, !p);
}