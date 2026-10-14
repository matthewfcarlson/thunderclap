class C_165750 {
    char pad[12];

  public:
    bool Set(int a);
};

bool C_165750::Set(int a) {
    *(int*)((char*)this + 12) = a;
    return true;
}
