//#include <sys/types.h>
//#include <sys/wait.h>
//#include <errno.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <string>
//#include <sysexits.h>
//#include <unistd.h>
//#include <fcntl.h>
//#include <iostream>
//using namespace std;
//
//
//char * getinput(char * buffer, size_t buflen)
//{
//    printf("$$ "); // print prompt (printf requires %% to print %)
//
//    // fgets reads in one line at a time from standard input
//    // stores it into the cstring pointed to by buffer, stops when either:
//    //      1) buflen - 1 chars are read
//    //      2) newline char is read
//    //      3) EOF marker is reached
//    // on success, fgets returns a ptr to the cstring pointed to by buff
//    // when an EOF marker is reached, a null ptr is returned
//    return fgets(buffer, buflen, stdin);
//}
//
//void fileReDir(char * op, char * file)
//{
////    char c;
//
//    //check for read command
//    if(strcmp(op, "<") == 0)
//    {
//        int fd = open("text.txt", O_WRONLY|O_CREAT, 0777);
//        dup2(fd, 1);
//        close(fd);
//        execlp("/bin/cat", "cat", file, (char*)0);
//
//
////        FILE * pFile = fopen(file, "r");
////        FILE * pTemp = fopen("temp.txt", "w");
////        while ((c = getc(pFile)) != EOF)
////        {
////            putc(c, pTemp);
////        }
//    }
//
//    //check for write command
//    if(strcmp(op, ">") == 0)
//    {
//        int fd = open(file, O_WRONLY|O_CREAT, 0777);
//        dup2(fd, 1);
//        close(fd);
//        execlp("/bin/cat", "cat", "text.txt", (char*)0);
//
////        FILE * pFile = fopen(file, "w");
////        FILE * pTemp = fopen("temp.txt", "r");
////        while ((c = getc(pTemp)) != EOF)
////        {
////            putc(c, pFile);
////        }
//    }
//
//    //check for append command
//    if(strcmp(op, ">>") == 0)
//    {
//        int fd = open(file, O_WRONLY| O_APPEND | O_CREAT, 0777);
//        dup2(fd, 1);
//        close(fd);
//        execlp("/bin/cat", "cat", "text.txt", (char*)0);
//
//        cout << "Oh no I'm inside append!" << endl;
//
//
////        FILE * pFile = fopen(file, "a");
////        FILE * pTemp = fopen("temp.txt", "r");
////        while ((c = getc(pTemp)) != EOF)
////        {
////            putc(c, pFile);
////        }
//    }
//
//    return;
//}
//
//
//int main(int argc, char ** argv)
//{
//    char buf[1024];
//    pid_t pid; // data type for process ID numbers
//    int status;
//    char * tok;
//
//    while (getinput(buf, sizeof(buf)))
//    {
//        //echo the command
//        cout << buf << endl;
//
//        buf[strlen(buf) -1] = '\0'; // replaces newline with NULL
//
//        //Parse the command for "exit", "read", "write", or "append"
//        tok = strtok(buf, " ");
//
//        //check for "exit", if so, then exit
//        if (strcmp(tok, "exit") == 0)
//            exit(0);
//
//        // call fork to create a new process, a copy of the caller (parent process)
//        // fork returns a 0 to the child, and the non-neg process ID # of the child process to the parent
//        if ((pid = fork()) == -1) // if the PID is less -1, then there is an error
//        {
//            fprintf(stderr, "shell: can't fork: %s\n", strerror(errno));
//            continue;
//        }
//        else if (pid == 0) // child
//        {
//            while (tok != NULL)
//            {
//                //get operator
//                tok = strtok(NULL, " ");
//                char * op = tok;
//
//                //if operator is a pipe, find the new command
//                if (strcmp(op, "|"))
//                {
//                    //2 calls to strtok to skip the | and the command (we only need to work with the operators)
//                    tok = strtok(NULL, " ");
//
//                    tok = strtok(NULL, " ");
//                    op = tok;
//                }
//
//                //get file name
//                tok = strtok(NULL, " ");
//                char * file = tok;
//
//                fileReDir(op, file);
//
//                //check for more tokens (i.e. pipe or null)
//                tok = strtok(NULL, " ");
//            }
//            exit(EX_OK);
//        }
//
//        // we want the parent to wait for the child process to finish, and we do this by calling waitpid, specifying which process to wait for: the pid argument (the process ID of the child)
//        // waitpid returns the termination status of the child (the status variable)
//        // in this program, we don't do anything with the status variable
//
//        if ((pid = waitpid(pid, &status, 0)) < 0) // parent
//            fprintf(stderr, "shell: waitpid error: %s\n", strerror(errno));
//    }
//    exit(EX_OK);
//}
