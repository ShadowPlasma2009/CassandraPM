// src/updatelocal.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include.h"

int update(const char repo_url[], const char config_path[]) {
  
  printf("Checking for cpm directory in /etc...\n");
  if (!access("/etc/cpm", F_OK) == 0) {
    printf("cpm directory doesn't exist in /etc. Creating...\n");
    system("mkdir -p %s", config_path);
  } else {
    printf("cpm directory exists in /etc. Skipping...\n");
  }

  printf("Repo URL: %s", repo_url);
  printf("Config Path: %s", config_path);
  
  int updated_status = system("curl -s -o %s", repo_url);

  if (updated_status == 0) {
    printf("Local package database update successfully!\n");
    return 0;
  } else {
    printf("Update failed! :<\n");
    return 1;
  }
}
