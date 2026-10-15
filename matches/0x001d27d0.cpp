struct Item {
    char c;
    char pad[63];
};
class Table {
  public:
    int head;
    Item items[256];
    int vals[256];
    Table();
};
Table::Table() {
    head = 0;
    for (int i = 0; i < 256; i++) {
        items[i].c = '0';
        vals[i] = 0;
    }
}