struct Data_192a60 {
    int a;
    int b;
    int c;
};
class Owner_192a60 {
  public:
    char pad[0x78];
    int m78;
    int m7c;
    int m80;
    bool Set(Data_192a60* d);
};
bool Owner_192a60::Set(Data_192a60* d) {
    m78 = d->a;
    m7c = d->b;
    m80 = d->c;
    return true;
}
