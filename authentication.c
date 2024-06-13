#include "authentication.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

User users[MAX_USERS];
int userCount = 0;

void loadUsers() {
  FILE* file = fopen(USER_FILE, "rb");
  if(file == NULL) {
    perror("Error opening user file");
    return;
  }
  fread(&userCount, sizeof(int), 1, file);
  fread(users, sizeof(User), userCount, file);
  fclose(file);
}

void saveUsers() {
  FILE* file = fopen(USER_FILE, "wb");
  if(file == NULL) {
    perror("Error opening user file");
    return;
  }
  fwrite(&userCount, sizeof(int), 1, file);
  fwrite(users, sizeof(User), userCount, file);
  fclose(file);
}

void generateSalt(unsigned char* salt) {
  if(RAND_bytes(salt, SALT_LEN) != 1) {
    fprintf(stderr, "Error generating salt\n");
    exit(1);
  }
}