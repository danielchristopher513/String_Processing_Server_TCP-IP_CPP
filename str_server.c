#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 800
#define PORT 8080
#define SA struct sockaddr
void uppr(char *buff){
    int i=0;
    while(buff[i])
        {
            buff[i] = toupper(buff[i]);
            i++;
        }
}
void lwr(char *buff){
    int i=0;
    while(buff[i])
        {
            buff[i] = tolower(buff[i]);
            i++;
        }
}

void rev(char *str){
       int len = strlen(str); // use strlen() to get the length of str string  
      char temp;
    // use for loop to iterate the string   
    for (int i = 0; i < len/2; i++)  
    {  
        // temp variable use to temporary hold the string  
        temp = str[i];  
        str[i] = str[len - i - 1];  
        str[len - i - 1] = temp;  
    }  
}  

int len(char *str)
{
    int len = strlen(str);
    return (len);
}

int isPalindrome(char *string){
 int flag = 1;  
      
    //Converts the given string into lowercase  
    for(int i = 0; i < strlen(string); i++){  
        string[i] = tolower(string[i]);  
    }  

    //printf("string length = %ld \n",strlen(string));
    //printf("here!! \n");
      
    //Iterate the string forward and backward, compare one character at a time   
    //till middle of the string is reached  
    for(int i = 0; i < strlen(string)/2; i++){  
        if(string[i] != string[strlen(string)-i-1]){  
            flag = 0;  
            break;  
        }  
    }
    return flag;  
}
int panagram(char *s){
     int i,used[26]={0},total=0;
    for(i=0;s[i]!='\0';i++)
    {
        if('a'<=s[i] && s[i]<='z')
        {
            total+=!used[s[i]-'a'];
            used[s[i]-'a']=1;
        }
        else if('A'<=s[i] && s[i]<='Z')
        {
            total+=!used[s[i]-'A'];
            used[s[i]-'A']=1;
        }
    }
    if(total==26)
     return 1;
    else
     return 0;
}
int anagram(char *array1,char *array2){
    int num1[26] = {0}, num2[26] = {0}, i = 0;
 
    while (array1[i] != '\0')
    {
        num1[array1[i] - 'a']++;
        i++;
    }
    i = 0;
    while (array2[i] != '\0')
    {
        num2[array2[i] -'a']++;
        i++;
    }
    for (i = 0; i < 26; i++)
    {
        if (num1[i] != num2[i])
            return 0;
    }
    return 1;
}
int isogram(char *str){
     for(int i = 0 ; i<strlen(str) ; i++)
    {
        for(int j = i+1 ; j <strlen(str) ; j++)
        {
            if(str[i] == str[j])
            {
                return 0;
            }
        }
    }
    return 1;
}
// Function designed for chat between client and server.
void func(int connfd)
{
    char buff[MAX];
    int n,a=0,l;
    char b[MAX]; // copy of the string sent from the client

    // infinite loop for chat
    for (;;) {
        bzero(buff, MAX);
   
        // read the message from client and copy it in buffer
        read(connfd, buff, sizeof(buff));


        // if msg contains "Exit" then server exit and chat ended.
        if (strncmp("exit", buff, 4) == 0) 
        {
            printf("Server Exit...\n");
            break;
        }

        char ch = buff[0]; //Contains the info what operation to perform
        strcpy(b,buff);
        bzero(buff, MAX);
        int i = 0,j = 0;

        for (i = 2; i <strlen(b)-1; i++)
        { 
          buff[i-2] = b[i]; // updating the buffer with just the string to be processed
        }
char buffer[MAX];
        //buff[i-2]=0;
        if(ch<'7')
        printf("From client: %s \n", buff);
        if(ch=='7'){
           int i=0;
            int j=0,a=0;
        while(buff[i]!='#')
          i++;
          a=i;
          i++;
        while(buff[i]){
          buffer[j]=buff[i];
          i++;
          j++;
        }
        buff[a]=0;
        buffer[j]=0;
        printf("From client: %s and %s\n", buff,buffer);
        }
        switch (ch)
        {
        case '1':
            uppr(buff);
            break;
        case '2':
            lwr(buff);
            break;
        case '3':
            a = isPalindrome(buff);
            if(a == 1)
            {
                strcpy(buff,"is a PALINDROME");
            }
            else 
            {
                strcpy(buff,"is NOT A PALINDROME");
            }
            break;
        case '4':
            rev(buff);
            break;
        case '5':
            l = len(buff);
            bzero(buff, MAX);
            buff[0] = l+'0';
            //printf("length = %s \n",buff);
            break;
        case '6':
            a = panagram(buff);
            if(a == 1)
            {
                strcpy(buff,"is a PANAGRAM");
            }
            else 
            {
                strcpy(buff,"is NOT A PANAGRAM");
            }
            break;
            case '7':a = anagram(buff,buffer);
            if(a == 1)
            {
                strcpy(buff,"are  ANAGRAMS");
            }
            else 
            {
                strcpy(buff,"are not  ANAGRAMS");
            }
                     
            break;
            case '8':
            a = isogram(buff);
            if(a == 1)
            {
                strcpy(buff,"is a ISOGRAM");
            }
            else 
            {
                strcpy(buff,"is not  a ISOGRAM");
            }
            break;
            case '#':
            default :
              strcpy(buff,"Invalid option \nEnter choice#<str> format \n");
              break;
        };

        // and send that buffer to client
        write(connfd, buff, sizeof(buff));

    }
}
   
// Driver function
int main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;
   
    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
   
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
   
    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");
   
    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);
   
    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("server accept failed...\n");
        exit(0);
    }
    else
        printf("server accept the client...\n");
   
    // Function for chatting between client and server
    func(connfd);
   
    // After chatting close the socket
    close(sockfd);
}