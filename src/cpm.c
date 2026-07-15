// src/cpm.c

#include <stdio.h>
#include <string.h>
#include "include.h"

int main(int argc, char *argv[]) {
  const char VERSION[] = "0.04-dev";
  const char REPO[] = "https://github.com/ShadowPlasma2009/cpm/res";
  const char CONFIG[] = "$HOME/Projects/cpm/res";
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
  } else if (argc == 4 && (strcmp(argv[1], "install") == 0) && (strcmp(argv[3], "-R") == 0)) {
  	rinstall(argv[2], REPO, CONFIG, PREFIX, TEMP);
  } else if (argc == 4 && (strcmp(argv[1], "install") == 0) && (strcmp(argv[3], "-T") == 0)) {
    tinstall(argv[2], PREFIX, TEMP);
  }
  return 0;
}

int usage(void) {
  printf("Usage: cpm <command> [arguments]\n");
  return 0;
}
