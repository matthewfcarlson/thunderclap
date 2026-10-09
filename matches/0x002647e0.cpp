class X { public: char pad[0xC]; unsigned char a; char padD; unsigned char b; unsigned char target(int,int,int,int); unsigned char first(int,int,int,int); unsigned char second(int,int,int,int); };
unsigned char X::target(int x,int y,int z,int w) {
    if (!a) return 0;
    if (!b) return first(x,y,z,w);
    return second(x,y,z,w);
}