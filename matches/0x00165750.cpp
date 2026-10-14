class C {
    char pad[12];

  public:
    bool Set(int a);
};

bool C::Set(int a) {
    *(int*)((char*)this + 12) = a;
    return true;
}
