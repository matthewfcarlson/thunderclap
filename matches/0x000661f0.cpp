struct Provider {
    char pad[0x2c];
    void* item;
};
extern Provider* gProvider;
struct Active {
    float compute();
};
struct Obj {
    void* item;
    Active* active;
    char pad[0x35c];
    float result;
    float offset;
    char flag;
    void update();
};
void Obj::update() {
    if (active) {
        if (!item)
            item = gProvider->item;
        if (item) {
            float x = active->compute();
            flag = 1;
            result = x + offset;
        }
    }
}