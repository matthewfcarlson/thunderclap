class T {
  public:
    char pad[8];
    char gap[4];
    int m_c;
    bool Return(int a);
};

bool T::Return(int a) {
    m_c = a;
    return true;
}
