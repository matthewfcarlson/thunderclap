struct Data {
    int a;
    int b;
    int c;
};
class Owner {
  public:
    char pad[0x78];
    int m78;
    int m7c;
    int m80;
    bool Set(Data* d);
};
bool Owner::Set(Data* d) {
    m78 = d->a;
    m7c = d->b;
    m80 = d->c;
    return true;
}
