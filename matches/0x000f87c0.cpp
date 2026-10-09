struct Data { char pad[0x0c]; int* values; int count; };
class Obj { public: Data* root; void Next(int, int, int); void F(int index, int b, int c); };
void Obj::F(int index, int b, int c) {
    if (index < 0) return;
    int value;
    if (index <= root->count) value = root->values[index];
    else value = 0;
    Next(value, b, c);
}
