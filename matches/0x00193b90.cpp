struct Inner_193b90 {
    char c;
};

class Obj_193b90 {
  public:
    char pad[0xa8];
    Inner_193b90 m;
    Inner_193b90* GetBody();
};

Inner_193b90* Obj_193b90::GetBody() {
    return &m;
}