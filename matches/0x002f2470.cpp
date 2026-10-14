class Vec3_2f2470 {
  public:
    int x, y, z;
};
class Arr_2f2470 {
  public:
    int count;
    int capacity;
    Vec3_2f2470* data;
    void Grow(int);
    void Insert(int index, Vec3_2f2470* value);
};
void Arr_2f2470::Insert(int index, Vec3_2f2470* value) {
    if (count >= capacity)
        Grow(count * 2);
    int i;
    for (i = count; i > index; --i)
        data[i] = data[i - 1];
    data[index] = *value;
    ++count;
}
