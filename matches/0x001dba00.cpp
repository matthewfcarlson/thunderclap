class X {
  public:
    char pad[0x38];
    char* value;
    char* Get(int index);
};
char* X::Get(int index) {
    return value + (index * 16);
}