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
//void testFunc()
//{
//    cout << "I am in testFunc" << endl;
//    execlp("/bin/cat","cat", "out2.c", (char *) 0);
//    /*  If execlp() is successful, we should not reach this next line. */
//    printf("The call to execlp() was not successful.\n");
//    exit(127);
//}
//
//int main(int argc, char ** argv)
//{
//    pid_t pid;
//    char buf[1024];
//    int status;
//    char * tok;
//
//    while (getinput(buf, sizeof(buf)))
//    {
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
//        if ((pid = fork()) == -1) // if the PID is less -1, then there is an error
//        {
//            fprintf(stderr, "shell: can't fork: %s\n", strerror(errno));
//            continue;
//        }
//        else if (pid == 0) /* We are in the child. */
//        {
//            printf("I am the child, about to call cat using execlp.\n");
//
//            tok = strtok(NULL, " ");
//            while (tok != NULL)
//            {
//                //get operator
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
//                //fileReDir(op, file);
////                testFunc();
//                cout << "I am in testFunc" << endl;
//                execlp("/bin/cat","cat", "out2.c", (char *) 0);
//                /*  If execlp() is successful, we should not reach this next line. */
//                printf("The call to execlp() was not successful.\n");
//                exit(127);
//
//                //check for more tokens (i.e. pipe or null)
//                cout << "I made it out!" << endl;
//                tok = strtok(NULL, " ");
//            }
//            exit(EX_OK);
//        }
//        sleep(2);
//        if ((pid = waitpid(pid, &status, 0)) < 0) // parent
//        {
//            cout << endl << endl << "PID: " << pid << endl;
//            fprintf(stderr, "shell: waitpid error: %s\n", strerror(errno));
//        }
//        cout << endl;
//    }
//    exit(EX_OK);
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
