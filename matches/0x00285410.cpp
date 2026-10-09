class Item {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool Match(int);
};
class Container {
  public:
    char pad[0x14];
    unsigned int count;
    Item* items[1];
    unsigned int Find(int value);
};
unsigned int Container::Find(int value) {
    unsigned int i = 0;
    while (i < count) {
        if (items[i]->Match(value) == true)
            return (unsigned int)items[i];
        ++i;
    }
    return 0;
}