struct Temp_27a590 {
    char data[8];
    void Build(int);
    void Finish();
};
struct Item_27a590 {
    char data[8];
    void Copy(Temp_27a590*);
};
class Obj_27a590 {
  public:
    char pad[0xa0];
    int values[20];
    int count;
    void Add(int, int);
};
void Obj_27a590::Add(int a, int b) {
    Temp_27a590 t;
    if (count < 20) {
        t.Build(a);
        ((Item_27a590*)((char*)this + count * 8))->Copy(&t);
        t.Finish();
        values[count] = b;
        ++count;
    }
}