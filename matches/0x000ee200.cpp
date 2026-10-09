class Ref {
  public:
    virtual void f0();
    virtual void f1();
};
class ImageSelector {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    char pad[0x150 - 4];
    Ref* items[64];
};
void ImageSelector::v21() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (items[i * 8 + j]) {
                items[i * 8 + j]->f1();
                items[i * 8 + j] = 0;
            }
}