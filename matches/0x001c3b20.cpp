class Sub {
  public:
    void Fn();
};

class C {
  public:
    char pad[8];
    Sub* mSub;
    void Forward();
};

void C::Forward() {
    mSub->Fn();
}
