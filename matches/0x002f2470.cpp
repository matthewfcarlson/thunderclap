class Vec3 {
  public:
    int x, y, z;
};
class Arr {
  public:
    int count;
    int capacity;
    Vec3* data;
    void Grow(int);
    void Insert(int index, Vec3* value);
};
void Arr::Insert(int index, Vec3* value) {
    if (count >= capacity)
        Grow(count * 2);
    int i;
    for (i = count; i > index; --i)
        data[i] = data[i - 1];
    data[index] = *value;
    ++count;
}
