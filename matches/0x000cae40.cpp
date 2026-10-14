class Target_cae40 {
    char pad[0xb8];

  public:
    void Set(int value);
};
void Target_cae40::Set(int value) {
    *(int*)((char*)this + 0xb8) = value;
}