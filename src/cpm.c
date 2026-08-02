// src/cpm.c

#include "include.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  // Build config by first expanding
  // the home directory.
  const char *home = getenv("HOME");
  char CONFIG[256];
  snprintf(CONFIG, sizeof(CONFIG), "%s/Projects/cpm/res", home);

  const char REPO[] = "https://raw.githubusercontent.com/ShadowPlasma2009/CassandraPM/main/res";
  const char VERSION[] = "0.1-dev";
  const char PREFIX[] = "$HOME/cpm/usr";
  const char TEMP[] = "$HOME/cpm/tmp";

  if (argc == 1) {
    usage();
  } else if (argc == 2 && strcmp(argv[1], "help") == 0) {
    help(VERSION);
  } else if (argc == 2 && strcmp(argv[1], "update") == 0) {
    update(REPO, CONFIG);
  } else if (argc == 2 && strcmp(argv[1], "list") == 0) {
    list(CONFIG);
  } else if (argc == 4 && (strcmp(argv[1], "install") == 0) &&
             (strcmp(argv[3], "-R") == 0)) {
    rinstall(argv[2], REPO, CONFIG, PREFIX, TEMP);
  } else if (argc == 4 && (strcmp(argv[1], "install") == 0) &&
             (strcmp(argv[3], "-T") == 0)) {
    tinstall(argv[2], PREFIX, TEMP);
  }
  return 0;
}

int usage(void) {
  printf("Usage: cpm <command> [arguments]\n");
  return 0;
}
