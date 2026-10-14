class Obj_14cea0 {
  public:
    char pad[0xc];
    void* mField;
    bool Fn(void* arg);
};

bool Obj_14cea0::Fn(void* arg) {
    mField = arg;
    return true;
}
