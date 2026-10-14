// Same code shape as 0x000244e0 (propagated; names are from that function)
class Helper_24510 {
  public:
    void Call(int);
};
class Owner_24510 {
  public:
    char pad[0x44];
    Helper_24510* mHelper;
};
class Outer_24510 {
  public:
    Owner_24510* mOwner;
    int pad[2];
    int count;
    int items[1];
    void run();
};
void Outer_24510::run() {
    int i = 0;
    if (count > 0) {
        int* p = items;
        do {
            mOwner->mHelper->Call(*p);
            ++i;
            ++p;
        } while (i < count);
    }
}
