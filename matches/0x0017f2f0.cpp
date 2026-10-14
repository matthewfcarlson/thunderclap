class Obj {
  public:
    char m_pad[12];
    char m_val;
    char Set(char c);
};
char Obj::Set(char c) {
    m_val = c;
    return 1;
}