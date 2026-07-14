// src/updatelocal.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include.h"

int update(const char repo[], const char config[]) {
  
  printf("Checking for cpm config directory in %s...\n", config);
  if ((!access(config, F_OK)) == 0) {
    printf("cpm directory doesn't exist in %s. Creating...\n", config);

    char mkdir_command[128];
    snprintf(mkdir_command, sizeof(mkdir_command),
             "mkdir -p %s", config);
    system(mkdir_command);
  } else {
    printf("cpm directory exists in %s. Skipping...\n", config);
  }

  printf("Repo URL: %s\n", repo);
  printf("Config Path: %s\n", config);
 
  char curl_command[256];
  snprintf(curl_command, sizeof(curl_command),
           "curl -s -o %s/packages.db %s", config, repo);
  int updated_status = system(curl_command);

  if (updated_status == 0) {
    printf("Local package database update successfully!\n");
    return 0;
  } else {
    printf("Update failed! :<\n");
    return 1;
  }
}
