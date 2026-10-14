struct V {
    int a;
    int b;
    int c;
};

class C_16e770 {
  public:
    char pad[0x20];
    bool Set(V* p);
};

bool C_16e770::Set(V* p) {
    *(int*)((char*)this + 0x20) = p->a;
    *(int*)((char*)this + 0x24) = p->b;
    *(int*)((char*)this + 0x28) = p->c;
    return true;
}
