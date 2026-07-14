// src/cpm.c

#include <stdio.h>
#include <string.h>
#include "include.h"

int main(int argc, char *argv[]) {
  const char version[] = CPM_VERSION;
  const char repoURL[] = CPM_REPO_URL;
  const char configPATH[] = CPM_CONFIG_PATH;
  const char prefix[] = CPM_PREFIX;
  const char cpmTMP[] = CPM_TMP;

  if (argc == 1) {
    usage();
    return 0;
  } else if (argc == 2 && strcmp(argv[1], "help") == 0) {
    help(version);
    return 0;
  } else if (argc == 2 && strcmp(argv[1], "update") == 0) {
    update(repoURL, configPATH);
  } else if (argc == 2 && strcmp(argv[1], "search") == 0) {
    search(configPATH);
  } else if (argc == 4 && (strcmp(argv[1], "install") == 0) && (strcmp(argv[3], "-R") == 0)) {
    char packageName[] = argv[2];
  	rinstall(packageName, repoURL, prefix, cpmTMP);
  }

  return 0;
}

void usage(void) {
  printf("Usage: cpm <command> [arguments]\n");
}
