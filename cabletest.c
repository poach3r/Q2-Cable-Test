#include <stdio.h>
#include <time.h>

int main() {
  int ttime, i;
  printf("Loading...");

  FILE * fp;
  fp = fopen("cabletest.txt", "w");
  for (i = 0; i < (1024 * 1024); i++) {
    fseek(fp, (1024 * 1024), SEEK_CUR);
    fprintf(fp, "C");
  }
  fclose(fp);

  char newName[100];
  char oldName[100] = "cabletest.txt";

  printf("\n\nEnter Location of Quest 2, please include \\cabletest.txt: ");
  scanf("%s", newName);

  printf("Starting...\n");

  time_t begin = time(NULL);

  if (rename(oldName, newName) == 0) {
    printf("\nStep 1 Complete.\n");
  } else {
    perror(oldName);
    perror(newName);
  }
  if (rename(newName, oldName) == 0) {
    printf("Step 2 Complete.\n");
  } else {
    perror(oldName);
    perror(newName);
  }
  time_t end = time(NULL);
  ttime = end - begin;
  printf("\n\nOperation took %d Seconds to Complete\n", ttime);
  return 0;
}
