struct Item {
    char pad[0x4a0];
    float value;
};
struct Container {
    char pad[0x10];
    int count;
    Item** items;
    float target();
};
float Container::target() {
    float result = 3.402823466e+38f;
    for (int i = 0; i < count; ++i) {
        float value = items[i]->value;
        if (value < result)
            result = value;
    }
    return result;
}
