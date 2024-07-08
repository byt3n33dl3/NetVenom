void
ksa(unsigned char * S, const char * key, unsigned const int len);

void
prga(unsigned char * S, unsigned char * K, unsigned const int len);

void
rc4crypt(char * plaintext, unsigned const char * K, unsigned const int len);

void
rc4decrypt(char * ciphertext, unsigned const char * K, unsigned const int len);
