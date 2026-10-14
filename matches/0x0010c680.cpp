class T_10c680 {
  public:
    char pad[8];
    char gap[4];
    int m_c;
    bool Return(int a);
};

bool T_10c680::Return(int a) {
    m_c = a;
    return true;
}
