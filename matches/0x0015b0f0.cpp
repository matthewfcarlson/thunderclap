struct S_15b0f0 {
    int a;
    int b;
    int c;
};

class Obj_15b0f0 {
  public:
    char pad[0x74];
    int m74;
    int m78;
    int m7c;
    bool Set(S_15b0f0* p);
};

bool Obj_15b0f0::Set(S_15b0f0* p) {
    m74 = p->a;
    m78 = p->b;
    m7c = p->c;
    return true;
}
