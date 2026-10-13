class Obj {
  public:
    char pad[0x2c];
    int m_field;
    bool Fn(int value);
};
bool Obj::Fn(int value) {
    m_field = value;
    return true;
}