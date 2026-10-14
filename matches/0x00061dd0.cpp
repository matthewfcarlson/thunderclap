class T_61dd0 {
  public:
    char Pad[0xa8];
    char Value;
    char Set(char x);
};
char T_61dd0::Set(char x) {
    Value = x;
    return 1;
}
