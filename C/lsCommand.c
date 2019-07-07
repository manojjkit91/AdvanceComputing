/*
 * To demonstrate the concept of linux 'ls' command in a C program
 */

#include <sys/types.h>
#include <sys/dir.h>
#include <sys/param.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <unistd.h> 

#define MAX_BUF_SZ  1024
#define PERM_BUF_SZ 30
#define DATA_SZ     256

static char permBuf [ PERM_BUF_SZ ];
char        pathName [ MAXPATHLEN ];


const char *getPerms ( mode_t mode )
{
  char ftype = '?';
  if (S_ISREG(mode)) ftype = '-';
  if (S_ISLNK(mode)) ftype = 'l';
  if (S_ISDIR(mode)) ftype = 'd';
  if (S_ISBLK(mode)) ftype = 'b';
  if (S_ISCHR(mode)) ftype = 'c';
  if (S_ISFIFO(mode)) ftype = '|';
  sprintf(permBuf, "%c%c%c%c%c%c%c%c%c%c %c%c%c", ftype,
  mode & S_IRUSR ? 'r' : '-',
  mode & S_IWUSR ? 'w' : '-',
  mode & S_IXUSR ? 'x' : '-',
  mode & S_IRGRP ? 'r' : '-',
  mode & S_IWGRP ? 'w' : '-',
  mode & S_IXGRP ? 'x' : '-',
  mode & S_IROTH ? 'r' : '-',
  mode & S_IWOTH ? 'w' : '-',
  mode & S_IXOTH ? 'x' : '-',
  mode & S_ISUID ? 'U' : '-',
  mode & S_ISGID ? 'G' : '-',
  mode & S_ISVTX ? 'S' : '-');
  return ( const char * ) permBuf;
}

void dieWithError ( char *msg )
{
  perror ( msg );
  exit ( 0 );
}

static int one ( const struct dirent *unused )
{
  return 1;
}

int main ( int argc, char *argv[] )
{
  /* To count number of dirFiles/directory */
  int count;
  /* For loop */
  int i;
  /** To direct */
  struct direct **dirFiles;
  /* To display file or file system status */
  struct stat statBuf;
  /* For date string */
  char dateStr [ DATA_SZ ];
  /* For user password */
  struct passwd pwent;
  /* For user password */
  struct passwd *pwEntP;
  /* For group  */
  struct group grp;
  /* For group  */
  struct group *grpP;
  /* For local time */
  struct tm time;
  /* For getpwuid_r () */
  char buf[MAX_BUF_SZ];
  /* getcwd() : To get current working directory  */
  if ( !getcwd ( pathName, sizeof(pathName) ) )
  {
    dieWithError("Error getting pathName\n");
  }
  /** scandir() : Scans a directory for matching enteries */
  count = scandir ( pathName, &dirFiles, one, alphasort );

  if ( count > 0 )
  {
    
    printf("Total %d\n", count);
    for (i = 0 ; i < count; ++i)
    {
      /* stat() : To display file or file system status  */
      if ( stat ( dirFiles[i]->d_name, &statBuf ) == 0 )
      {
        /* Print out type, permissions, and number of links. */
        printf( "%10.10s", getPerms ( statBuf.st_mode ) );
        printf(" %d", (int) statBuf.st_nlink );
        /* getpwuid_r() : get password file entry  */  
        if ( !getpwuid_r ( statBuf.st_uid, &pwent, buf, sizeof(buf), &pwEntP ) )
        {
          printf ( " %s", pwent.pw_name );
        }
        else
        {
          printf ( " %d", statBuf.st_uid );
        }
        /* getprpid_r() : get group file entry */
        if ( !getgrgid_r ( statBuf.st_gid, &grp, buf, sizeof(buf), &grpP ) )
        {
          printf(" %s", grp.gr_name);
        } 
        else
        {
          printf(" %d", statBuf.st_gid);
        }
        /* Print size of file. */
        printf ( " %5d", (int) statBuf.st_size );
        /* To get local time */
        localtime_r ( &statBuf.st_mtime, &time );
        /* Get localized date string. */
        strftime ( dateStr, sizeof(dateStr), "%F %T", &time );
        printf ( " %s %s\n", dateStr, dirFiles[i]->d_name );
      }
      /* Frees the allocated memory */
      free ( dirFiles[i] );
    }
    /* Frees the allocated memory */
    free ( dirFiles );
  }
}
