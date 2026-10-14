class X_1dba00 {
  public:
    char pad[0x38];
    char* value;
    char* Get(int index);
};
char* X_1dba00::Get(int index) {
    return value + (index * 16);
}