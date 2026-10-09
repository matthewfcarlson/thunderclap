struct Temp {
    char data[8];
    void Build(int);
    void Finish();
};
struct Item {
    char data[8];
    void Copy(Temp*);
};
class Obj {
  public:
    char pad[0xa0];
    int values[20];
    int count;
    void Add(int, int);
};
void Obj::Add(int a, int b) {
    Temp t;
    if (count < 20) {
        t.Build(a);
        ((Item*)((char*)this + count * 8))->Copy(&t);
        t.Finish();
        values[count] = b;
        ++count;
    }
}