struct RoomLoader {
    int vft;
    int a;
    int b;
    int c;
    int d;
    int e;
    RoomLoader(int arg);
};
RoomLoader::RoomLoader(int arg) {
    a = 0;
    c = 0;
    d = 0;
    b = 0x60000701;
    vft = 0x421a04;
    e = arg;
}