struct Thing {
	char pad[8];
	char* p;
	char GetByte();
};

char Thing::GetByte() {
	return p[4];
}
