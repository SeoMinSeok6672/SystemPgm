1 #include <sys/types.h>
2 #include <sys/stat.h>
3 #include <dirent.h>
4 #include <pwd.h>
5 #include <grp.h>
6 #include <stdio.h>
7
8 char type(mode_t);
9 char *perm(mode_t);
10 void printStat(char*, char*, struct stat*);
11
12 /* 디렉터리 내용을 자세히 리스트한다. */
13 int main(int argc, char **argv)
14 {
15 DIR *dp;
16 char *dir;
17 struct stat st;
18 struct dirent *d;
19 char path[BUFSIZ+1];
21 if (argc == 1)
22 dir = ".";
23 else dir = argv[1];
24
25 if ((dp = opendir(dir)) == NULL) // 디렉터리 열기
26 perror(dir);
27
28 while ((d = readdir(dp)) != NULL) { // 디렉터리의 각 파일에 대해
29 sprintf(path, "%s/%s", dir, d->d_name); // 파일경로명 만들기
30 if (lstat(path, &st) < 0) // 파일 상태 정보 가져오기
31 perror(path);
32 printStat(path, d->d_name, &st); // 상태 정보 출력
33 putchar('\n');
34 }
35
36 closedir(dp);
37 exit(0);
38 }
40 /* 파일 상태 정보를 출력 */
41 void printStat(char *pathname, char *file, struct stat *st) {
42
43 printf("%5d ", st->st_blocks);
44 printf("%c%s ", type(st->st_mode), perm(st->st_mode));
45 printf("%3d ", st->st_nlink);
46 printf("%s %s ", getpwuid(st->st_uid)->pw_name,
getgrgid(st->st_gid)->gr_name);
47 printf("%9d ", st->st_size);
48 printf("%.12s ", ctime(&st->st_mtime)+4);
49 printf("%s", file);
50 }
52 /* 파일 타입을 리턴 */
53 char type(mode_t mode) {
54
55 if (S_ISREG(mode))
56 return('-');
57 if (S_ISDIR(mode))
58 return('d');
59 if (S_ISCHR(mode))
60 return('c');
61 if (S_ISBLK(mode))
62 return('b');
63 if (S_ISLNK(mode))
64 return('l');
65 if (S_ISFIFO(mode))
66 return('p');
67 if (S_ISSOCK(mode))
68 return('s');
69 }
