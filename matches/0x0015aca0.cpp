class X {
  public:
    void* GetStuff();
};
void* X::GetStuff() {
    return (char*)this + 0x60;
}
