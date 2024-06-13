#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
  char name[50];
  char phone[20];
  struct Contact* next;
} Contact;

Contact* createContact(const char* name,   const char* phone) {
  Contact* newContact = (Contact*)malloc(sizeof(Contact));
  if(newContact == NULL) {
    printf("Memory allocation failed.\n");
  }

}

int main(void) {
  
}