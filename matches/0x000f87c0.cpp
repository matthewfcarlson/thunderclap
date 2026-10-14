struct Data_f87c0 {
    char pad[0x0c];
    int* values;
    int count;
};
class Obj_f87c0 {
  public:
    Data_f87c0* root;
    void Next(int, int, int);
    void F(int index, int b, int c);
};
void Obj_f87c0::F(int index, int b, int c) {
    if (index < 0)
        return;
    int value;
    if (index <= root->count)
        value = root->values[index];
    else
        value = 0;
    Next(value, b, c);
}
