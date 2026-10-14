class Item_796a0 {
  public:
    char pad[0x1c];
    float value;
    void update(float);
};
class Owner_796a0 {
  public:
    char pad[0x374c];
    Item_796a0* items[20];
    int count;
    void run(float);
};
void Owner_796a0::run(float x) {
    for (int i = 0; i < count; ++i)
        items[i]->update(x + items[i]->value);
}
