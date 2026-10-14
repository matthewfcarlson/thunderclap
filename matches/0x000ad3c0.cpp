struct Item {
    char padding[0x4a4];
    float value;
};
struct Collection {
    char padding[0x10];
    int count;
    Item** items;
    float FUN_000ad3c0();
};
float Collection::FUN_000ad3c0() {
    float maximum = 1.1754943508222875e-38f;
    for (int i = 0; i < count; ++i) {
        float value = items[i]->value;
        if (value > maximum)
            maximum = value;
    }
    return maximum;
}