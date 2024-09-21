#include &lt;stdio.h&gt;
#include &lt;netdb.h&gt;
#include &lt;netinet/in.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;string.h&gt;
#include &lt;sys/socket.h&gt;
#include &lt;sys/types.h&gt;
#include &lt;unistd.h&gt; // read(), write(), close()
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

// Function designed for chat between client and server.
void func(int connfd)
{
char buff[MAX];
int n;
// infinite loop for chat
for (;;) {
bzero(buff, MAX);

// read the message from client and copy it in buffer
read(connfd, buff, sizeof(buff));=
// print buffer which contains the client contents
printf(&quot;From client: %s\t To client : &quot;, buff);
bzero(buff, MAX);
n = 0;
// copy server message in the buffer
while ((buff[n++] = getchar()) != &#39;\n&#39;)

;

// and send that buffer to client
write(connfd, buff, sizeof(buff));

// if msg contains &quot;Exit&quot; then server exit and chat ended.
if (strncmp(&quot;exit&quot;, buff, 4) == 0) {
printf(&quot;Server Exit...\n&quot;);
break;
}
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
printf(&quot;socket creation failed...\n&quot;);
exit(0);
}
else
printf(&quot;Socket successfully created..\n&quot;);
bzero(&amp;servaddr, sizeof(servaddr));

// assign IP, PORT
servaddr.sin_family = AF_INET;

servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(PORT);

// Binding newly created socket to given IP and verification
if ((bind(sockfd, (SA*)&amp;servaddr, sizeof(servaddr))) != 0) {
printf(&quot;socket bind failed...\n&quot;);
exit(0);
}
else
printf(&quot;Socket successfully binded..\n&quot;);

// Now server is ready to listen and verification
if ((listen(sockfd, 5)) != 0) {
printf(&quot;Listen failed...\n&quot;);
exit(0);
}
else
printf(&quot;Server listening..\n&quot;);
len = sizeof(cli);

// Accept the data packet from client and verification
connfd = accept(sockfd, (SA*)&amp;cli, &amp;len);
if (connfd &lt; 0) {
printf(&quot;server accept failed...\n&quot;);
exit(0);
}
else
printf(&quot;server accept the client...\n&quot;);

// Function for chatting between client and server
func(connfd);

// After chatting close the socket
close(sockfd);
}
