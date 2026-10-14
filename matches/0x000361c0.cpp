class C_361c0 {
    char pad[0x1b1c];
    int value;

  public:
    void F(char b);
};
void C_361c0::F(char b) {
    if (b)
        ++value;
    else
        --value;
}