#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "include.h"

int rinstall(char package[], const char repo[], const char config[], const char prefix[], const char temp[]) {
  if (!pkginstalled(package, config)) {
    printf("Package: %s already installed! To upgrade packages, ", package);
    printf("run `cpm upgrade`!\n");
    return 1;
  }

  char pdatabase[512];
  snprintf(pdatabase, sizeof(pdatabase), "%s/packages.db", config);
  if (access(pdatabase, F_OK) == -1) {
    printf("packages.db file inaccessible or doesn't exist.\n");
    printf("Run 'cpm update' first to fetch packages.db!\n");
    return 1;
  }

  printf("Installing %s...\n", package);

  FILE *db = fopen(pdatabase, "r");
  char line[256];
  // package names shoudn't be longer than 16 characters, right?
  char name[16], version[16], hasdeps[128];
  int found = 0;

  while (fgets(line, sizeof(line), db)) {
    if (sscanf(line, "%[^|]%[^|]%s", name, version, hasdeps) == 4) {
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

  printf("Installing %s (%s) from %s...\n", package, version, url);

  char command[512];

  printf("Creating essential directories if necessary...\n");

  if (access(prefix, F_OK) == 0) {
    snprintf(command, sizeof(command), "mkdir -p %s", prefix);
    system(command);
    printf("Created %s!\n", prefix);
  } else {
    printf("%s exists. Skipping...\n", prefix);
  }

  if (access(temp, F_OK) == 0) {
    snprintf(command, sizeof(command), "mkdir -p %s", temp);
    system(command);
    printf("Created %s!\n", temp);
  } else {
    printf("%s exists. Skipping...\n", temp);
  }

  // Download tar.gz package archive
  snprintf(command, sizeof(command), "curl -s -L -o %s/%s.tar.gz %s", temp, package, url);
  int curl_res = system(command);

  if (curl_res != 0) {
    printf("Error: Failed to download %s!\n", package);
    return 1;
  } else {
    printf("Downloaded '%s'! Proceeding to extract...\n", package);
  }

  // Extract downloaded tar package archive
  snprintf(command, sizeof(command), "tar -xzf %s/%s.tar.gz -C %s", temp, package, prefix);
  int ext_res = system(command);
  if (ext_res != 0) {
    printf("Error: Failed to extract package: %s\n", package);
    snprintf(command, sizeof(command), "rm -f %s/%s.tar.gz", temp, package);
    return 1;
  }

  snprintf(command, sizeof(command), "rm -f %s/%s.tar.gz", temp, package);
  system(command);

  printf("Successfully installed package: %s\n", package);

  // Package logging, format: yy/mm/dd|package
  if (!pkginstalled(package, config)) {
    char file[128], logline[128], date[12];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(date, sizeof(date), "%Y-%m-%d", t);

    snprintf(logline, sizeof(logline), "\nInstalled:%s|%s\n", package, date);
    snprintf(file, sizeof(file), "%s/pkglog.txt", config);
    FILE *logf = fopen(file, "a");
    fprintf(logf, "%s", logline);
    fclose(logf);
  } else {
    printf("Not logging package: %s. Already installed.\n", package);
  }

  if (!pkginstalled(package, config)) {
    char file[128];
    snprintf(file, sizeof(file), "%s/packages.installed", config);
    FILE *pkgs = fopen(file, "a");
    fprintf(pkgs, "%s\n", package);
    fclose(pkgs);
  } else {
    printf("Not adding package to installed package list. Package: %s is already installed.\n", package);
  }

  return 0;
}

int tinstall(char pkg_path[], const char prefix[], const char temp[]) {
  printf("TINSTALL!!!\n");
  return 0;
}

int pkginstalled(char package[], const char config[]) {
  char log_path[256];

  snprintf(log_path, sizeof(log_path), "%s/packages.installed", config);
  FILE *lfile = fopen(log_path, "r");
  if (!lfile) {
    return 1;
  }

  /* Use fgets to continously read lines from
   * packages.installed. Scan one element from line until
   * next whitespace and store into pkg. If successfully
   * scanned 1 element, compare pkg with package. If true,
   * close lfile and return 0. Since 0 means "succeeded", make
   * the return value practically inverted using ! before
   * you call this function elsewhere.
  */

  char line[64];
  char pkgcmp[64];

  while (fgets(line, sizeof(line), lfile)) {
    if (sscanf(line, "%63s", pkgcmp) == 1) {
      if (strcmp(pkgcmp, package) == 0) {
        fclose(lfile);
        return 0;
      }
    }
  }

  fclose(lfile);
  return 1;
}
