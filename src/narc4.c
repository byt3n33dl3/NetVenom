//arc4 implementation (https://en.wikipedia.org/wiki/RC4) - m0nad

void
swap(unsigned char * a, unsigned char * b)
{
  if (*a != *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
  }
}

void
ksa(unsigned char * S, const char * key, unsigned const int len)
{
  unsigned int i, j;
  for (i = 0; i < 256; i++) {
    S[i] = i;
  } 
  for (j = 0, i = 0; i < 256; i++) {
    j = (j + S[i] + key[i % len]) % 256;
    swap(S+i, S+j);
  }
}

void
prga(unsigned char * S, unsigned char * K, unsigned const int len)
{
  unsigned int i, j, k;
  for (i = 0, j = 0, k = 0; k < len; k++) {
    i = (i + 1) % 256;
    j = (j + S[i]) % 256;
    swap(S+i, S+j);
    K[k] = S[(S[i] + S[j]) % 256];
  }
}

void
rc4crypt(char * plaintext, unsigned const char * K, unsigned const int len)
{
  unsigned int i;
  for (i = 0; i < len; i++)
    plaintext[i] ^= K[i];
}

void
rc4decrypt(char * ciphertext, unsigned const char * K, unsigned const int len)
{
  unsigned int i;
  for (i = 0; i < len; i++)
    ciphertext[i] ^= K[i];
}

