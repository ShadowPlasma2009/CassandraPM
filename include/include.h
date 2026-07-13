// include/include.h
#ifndef INCLUDE_H
#define INCLUDE_H

#define CPM_VERSION "0.01-dev"
#define CPM_REPO_URL "https://github.com"
#define CPM_CONFIG_PATH "$HOME/cpm"
#define CPM_PREFIX "$HOME_cpmUsr"

void help(const char *version);
int update(const char *repo_url, const char *config_path);
void usage(void);

#endif
