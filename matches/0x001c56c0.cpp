class StoreBase {
  public:
    virtual void f0();
    virtual int f1(int);
    virtual void f2();
};
class Object {};
template <class T> class Store : public StoreBase {
  public:
    virtual int f1(int value);
};
template <> int Store<Object>::f1(int value) {
    return value + 8;
}
