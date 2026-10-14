class O_15ac50 {
    char p[0x38];

  public:
    bool Set(int x);
};

bool O_15ac50::Set(int x) {
    *(int*)(p + 0x38) = x;
    return true;
}
