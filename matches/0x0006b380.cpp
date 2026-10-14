class Obj_6b380 {
  public:
    char pad[0x44];
    int field;
    bool Set(int v);
};

bool Obj_6b380::Set(int v) {
    field = v;
    return true;
}
