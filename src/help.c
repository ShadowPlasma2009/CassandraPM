// src/help.c
#include <stdio.h>
#include "include.h"

int help(const char version[]) {
  printf("Cassandra Package Manager %s\n", version);
  printf("Usage: cpm <command> [arguments]\n");
  printf("\nCommands:\n");
  printf("  install <package> -R - Install a package from an online repository\n");
  printf("  install <pkg_path> -T - Install a local .tar.gz package\n");
  printf("  remove <package> - Remove specified package\n");
  printf("  update - Update local package database\n");
  printf("  upgrade - Upgrade all installed packages\n");
  printf("  list - List all available to install packages\n");
  printf("  help - Display this help message\n");

  printf("\nThis package manager is running in Moisturizer (6 in 1) mode!\n");

  return 0;
}
