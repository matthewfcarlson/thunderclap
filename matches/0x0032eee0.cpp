class X_32eee0 {
  public:
    char pad[0x88];
    void Set(int value);
};

void X_32eee0::Set(int value) {
    *(int*)((char*)this + 0x88) = value;
}
