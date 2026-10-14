class Owner_204060 {
  public:
    char pad[0x58c];
    short* items;
    int gap;
    int count;
    short* find_item(int a, int b);
};
short* Owner_204060::find_item(int a, int b) {
    if (a < 0 || b < 0)
        return 0;
    int i = 0;
    if (count > 0) {
        short* p = items;
        do {
            if (a == p[0] && b == p[1])
                return items + i * 0x2b;
            ++i;
            p += 0x2b;
        } while (i < count);
    }
    return 0;
}