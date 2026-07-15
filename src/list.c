// src/searchlocal.c
#include <stdio.h>
#include <stdlib.h>
#include "include.h"

int list(const char config_path[]) {
  char search_command[512];

  printf("Packages available in CPM repository:\n\n");
  snprintf(search_command, sizeof(search_command),
           "awk -F'|' '{printf \"%%-12s version: %%s\\n\", $1, $2}' %s/packages.db",
           config_path);
  system(search_command);

  printf("\nDependencies not listed. They will be ");
  printf("automatically resolved and installed alongside ");
  printf("the packages that need them.\n");
  return 0;
}
