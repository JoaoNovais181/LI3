#include <string.h>
#include <math.h>
#include <stdio.h>

// structs

typedef struct gh_user {
    char *pub_repos;
    char *id;
    char *login;
    char *type;
    char *createdat;
    char *followers;
    char *followerlist;
    char *following;
    char *followinglist;
    char *public_gists;
} *GH_USER; 

/*
struct Gh_user init_user(char *info) {
    struct user k;
    k.pub_repos = atoi(strsep(&info, ";"));
    k.id = strdup(strsep(&info, ";"));
    return k;
}
*/
 // mudar a ordem depois ver no ficheiro usersc
GH_USER separador (char *lines) {
    GH_USER k = malloc(sizeof(GH_USER));
        k->pub_repos = strdup(strsep(&lines, ";"));
        k->id = strdup(strsep(&lines, ";"));
        k->followers = strdup(strsep(&lines, ";"));
        k->followerlist = strdup(strsep(&lines, ";"));
        k->type = strdup(strsep(&lines, ";"));
        k->followinglist = strdup(strsep(&lines, ";"));
        k->public_gists = strdup(strsep(&lines, ";"));
        k->createdat = strdup(strsep(&lines, ";"));
        k->following = strdup(strsep(&lines, ";"));
        k->login = strdup(strsep(&lines, ";"));
    return k;
}
// função que valida o ID
int valid_Id (GH_USER k){

    if (strcmp ( "" ,k->id) == 0 ) return 0;
    else if (atoi(k->id) >= 0 && all_number(k->id)) return 1;
    return 0;

}

// função que valida followers
int valid_followers (GH_USER k){

    if (strcmp ( "" ,k->followers) == 0 ) return 0;
    else if (atoi(k->followers) >= 0 && all_number(k->followers)) return 1;
    return 0;

}

 // função que valida o type
int valid_type (GH_USER k){

    if (strcmp ( "User" , k->type) || strcmp ( "Bot" , k->type )|| strcmp ( "Organization" , k->type ) ) return 1;
    else return 0; 
 }

 // função que valida o public repos
int valid_pubrepos (GH_USER k){

    if (strcmp ( "" ,k->pub_repos) == 0 ) return 0;
    else if (atoi(k->pub_repos) >= 0 && all_number(k->pub_repos)) return 1;
    return 0;

}
 
 // função que ver se são todos números 
int all_number (char* str)
{
    for (int i = 0 ; str[i] ; i++)
        if (str[i]<48 || str[i]>57) return 0;

    return 1;
}

void show_user(GH_USER k){
    printf("public repos: %d, id: %s\n", k.public_repos, k.id);
}
int main() {
    FILE *data_file = fopen("users100.csv","r");
    char buffer[200];
    //char lines [200][200];
    char *lines [200];
    int i = 0;
    struct user users = NULL;
    if (data_file == NULL) {
        printf("Error when opening\n");
        return 1;
    }
    while(fgets(buffer, 200, data_file)){
        users = realloc(users,(i+1)sizeof(struct user));// realoca x de memória(adiciona)
        users[i] = init_user(buffer);
        //lines[i] = strdup(buffer);
        i++;
    }
    for (i = 0; i < 101; i++) {
        show_user(users[i]);
    }
    fclose(data_file);
    return 0;\
}
