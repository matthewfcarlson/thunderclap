class A_17f500 {
  public:
    char pad[12];
    char mField;
    char Set(char p);
};
char A_17f500::Set(char p) {
    mField = p;
    return 1;
}
