#include &lt;arpa/inet.h&gt; // inet_addr()
#include &lt;netdb.h&gt;
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;string.h&gt;
#include &lt;strings.h&gt; // bzero()
#include &lt;sys/socket.h&gt;
#include &lt;unistd.h&gt; // read(), write(), close()
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
void func(int sockfd)
{
char buff[MAX];
int n;
for (;;) {
bzero(buff, sizeof(buff));
printf(&quot;Enter the string : &quot;);
n = 0;
while ((buff[n++] = getchar()) != &#39;\n&#39;)
;
write(sockfd, buff, sizeof(buff));
bzero(buff, sizeof(buff));
read(sockfd, buff, sizeof(buff));
printf(&quot;From Server : %s&quot;, buff);
if ((strncmp(buff, &quot;exit&quot;, 4)) == 0) {
printf(&quot;Client Exit...\n&quot;);
break;
}
}
}

int main()
{
int sockfd, connfd;
struct sockaddr_in servaddr, cli;

// socket create and verification
sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd == -1) {
printf(&quot;socket creation failed...\n&quot;);
exit(0);
}
else
printf(&quot;Socket successfully created..\n&quot;);
bzero(&amp;servaddr, sizeof(servaddr));

// assign IP, PORT
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = inet_addr(&quot;127.0.0.1&quot;);
servaddr.sin_port = htons(PORT);

// connect the client socket to server socket
if (connect(sockfd, (SA*)&amp;servaddr, sizeof(servaddr))
!= 0) {
printf(&quot;connection with the server failed...\n&quot;);
exit(0);
}
else
printf(&quot;connected to the server..\n&quot;);

// function for chat

func(sockfd);

// close the socket
close(sockfd);
}
