class Image {
    char pad[0x60];

  public:
    unsigned int flags;
};
void Missing(Image*, const char*);
void BadLength(Image*, const char*);
void Finish(Image*, int);
void Target(Image* self, int p2, int p3) {
    if (((self->flags & 1) == 0 || (self->flags & 4) == 0) && (Missing(self, "No image in file"), p2 == 0))
        return;
    self->flags |= 0x18;
    if (p3 != 0)
        BadLength(self, "Incorrect IEND chunk length");
    Finish(self, p3);
}