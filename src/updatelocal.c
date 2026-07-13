// src/updatelocal.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include.h"

int update(const char repo_url[], const char config_path[]) {
  
  printf("Checking for cpm directory in /etc...\n");
  if ((!access("/etc/cpm", F_OK)) == 0) {
    printf("cpm directory doesn't exist in %s. Creating...\n", config_path);

    char mkdir_command[512];
    snprintf(mkdir_command, sizeof(mkdir_command),
             "mkdir -p %s", config_path);
    system(mkdir_command);
  } else {
    printf("cpm directory exists in %s. Skipping...\n", config_path);
  }

  printf("Repo URL: %s\n", repo_url);
  printf("Config Path: %s\n", config_path);
 
  char curl_command[512];
  snprintf(curl_command, sizeof(curl_command),
           "curl -s -o %s/packages.db %s", config_path, repo_url);
  int updated_status = system(curl_command);

  if (updated_status == 0) {
    printf("Local package database update successfully!\n");
    return 0;
  } else {
    printf("Update failed! :<\n");
    return 1;
  }
}
