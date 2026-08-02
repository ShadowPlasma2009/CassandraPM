// include/include.h
#ifndef INCLUDE_H
#define INCLUDE_H

// Define color escape codes
// all nice and in ascending order
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

#define BOLD    "\033[1m"
#define DIM     "\033[2m"
#define UNDER   "\033[4m"

#define RESET   "\033[0m"


int help(const char *version);
int update(const char *repo, const char *config);
int list(const char *config);
int rinstall(char *package, const char *repo, const char *config, const char *prefix, const char *temp);
int tinstall(char *pkg_path, const char *prefix, const char *temp);
int pkginstalled(char *package, const char *config);
int usage(void);

#endif
