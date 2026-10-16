class Player2 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void f();
};
class IRefCount {
  public:
    virtual void f();
};
class PlayerBink : public Player2, public IRefCount {
  public:
    virtual void f();
    int x;
};
void consume(PlayerBink*);
void PlayerBink::f() {
    PlayerBink b;
    consume(&b);
}