struct Obj {
    char pad1[0x36f0];
    int arr[20];  // 0x36f0
    int count;    // 0x3740
    int pad_3744; // 0x3744
    int divv;     // 0x3748

    void SetScale(int p);
};

void Obj::SetScale(int p) {
    if (p <= 0x14) {
        float local = (float)p / (float)divv;
        for (int i = 0; i < count; ++i) {
            arr[i] = (int)((float)arr[i] * local);
        }
        divv = p;
    }
}
