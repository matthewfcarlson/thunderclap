class O {
    char p[0x38];

  public:
    bool Set(int x);
};

bool O::Set(int x) {
    *(int*)(p + 0x38) = x;
    return true;
}
