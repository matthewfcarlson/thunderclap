struct V {
    int a;
    int b;
    int c;
};

class C {
  public:
    char pad[0x20];
    bool Set(V* p);
};

bool C::Set(V* p) {
    *(int*)((char*)this + 0x20) = p->a;
    *(int*)((char*)this + 0x24) = p->b;
    *(int*)((char*)this + 0x28) = p->c;
    return true;
}
