class FEDoBackScreen {
  public:
    virtual void f();
    FEDoBackScreen(int, unsigned char, unsigned char);
    char pad[0x38];
};
FEDoBackScreen::FEDoBackScreen(int a, unsigned char b, unsigned char c) {
    *(int*)((char*)this + 8) = -1;
    *(int*)((char*)this + 12) = -1;
    *(int*)((char*)this + 16) = a;
    *((char*)this + 20) = 0;
    *(int*)((char*)this + 0) = 0x40c0d4;
    *((char*)this + 0x34) = b;
    *((char*)this + 0x35) = c;
}
