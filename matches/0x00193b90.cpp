struct Inner {
    char c;
};

class Obj {
  public:
    char pad[0xa8];
    Inner m;
    Inner* GetBody();
};

Inner* Obj::GetBody() {
    return &m;
}