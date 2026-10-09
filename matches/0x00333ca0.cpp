namespace movie {
class Player2 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
};
class PlayerBink : public Player2 {
  public:
    char pad[0x20];
    unsigned char state;
    void vfunc_4();
};
void PlayerBink::vfunc_4() {
    state = 0;
    Player2* p = *(Player2**)((char*)this + 0x14);
    p->f7();
}
} // namespace movie