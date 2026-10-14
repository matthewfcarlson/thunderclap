class T {
  public:
    char Pad[0xa8];
    char Value;
    char Set(char x);
};
char T::Set(char x) {
    Value = x;
    return 1;
}
