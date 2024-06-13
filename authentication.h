#ifndef AUTHENTICATION.H
#define AUTHENTICATION.H

#include <openssl/sha.h>
#include <openssl/rand.h>

#define USER_FILE "users.txt"
#define MAX_USERS 100
#define USERNAME_LEN 50
#define HASH_LEN SHA256_DIGEST_LENGTH
#define SALT_LEN 16

typedef struct User {
    char username[USERNAME_LEN];
    unsigned char salt[SALT_LEN];
    unsigned char password_hash[HASH_LEN];
} User;

void loadUsers();
void saveUsers();
int addUser(const char* name, const char* password);
int authenticate(const char* username, const char* password);
void generateSalt(unsigned char* salt);
void hashPassword(const char* password, const unsigned char* salt, unsigned char* hash);

#endif