#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "include.h"

int rinstall(char package[], const char repo[], const char config[], const char prefix[], const char temp[]) {
  char pdatabase[512];
  snprintf(pdatabase, sizeof(pdatabase), "%s/packages.db", config);
  if (access(pdatabase) == NULL) {
    printf("packages.db file inaccessible or doesn't exist.\n");
    printf("Run 'cpm update' first to fetch packages.db!\n");
    return 1;
  } else {
    FILE *db = fopen(pdatabase, "r");
  }

  char line[256];
  char name[16], version[16], url[128], deps[128];
  int found = 0;

  while (fgets(line, sizeof(line), db)) {
    if (sscanf(line, "%[^|]|%[^|]|%[^|]|%s", name, version, url, deps) == 4) {
      if (strcmp(name, package) == 0) {
        found = 1;
        break;
      }
    }
  }
  fclose(db);

  if (!found) {
    printf("Error: No package '%s' found in database.\n", package);
    return 1;
  }

  if (strcmp(deps, "none") != 0) {
    printf("Resolving dependencies for %s...\n", package);
    char *dep = strtok(deps, ",");
    while (dep != NULL) {
      printf("Checking dependency: '%s'...\n", dep);
      rintstall(dep, repo, config, prefix, temp);
      dep = strtok(NULL, ",");
    }
  } else {
    printf("'%s' has no dependencies. Skipping...\n", package);
  }

  printf("Installing %s (%s) from %s...\n", package, version, url);
  
  char command[512];
  
  printf("Creating essential directories if necessary...");
  
  if (access(prefix) == NULL) {
    snprintf(command, sizeof(command), "mkdir -p %s", prefix);
    system(command);
    printf("Created %s!\n", prefix);
  } else {
    printf("%s exists. Skipping...\n", prefix);
  }

  if (access(temp) == NULL) {
    snprintf(command, sizeof(command), "mkdir -p %s", temp);
    system(command);
    printf("Created %s!\n", temp);
  } else {
    printf("%s exists. Skipping...\n", temp);
  }

  // Download tar.gz package archive
  snprintf(command, sizeof(command), "curl -s -L -o %s/%s.tar.gz %s", temp, package, url);
  int curl_worked = system(command);

  if (curl_worked != 0) {
    printf("Error: Failed to download %s\n!", package);
    return 1;
  } else {
    printf("Downloaded '%s'! Proceeding to extract...\n", package);
  }

  // Extract downloaded tar package archive


  return 0;
}

int tinstall(char pkg_path[], const char prefix[], const char temp[]) {
  printf("TINSTALL!!!\n");
  return 0;
}
