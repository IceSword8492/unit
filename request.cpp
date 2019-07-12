// Author: ’†‘º—GÆ
// http’ÊMŠÖŒW

#ifndef REQUEST
#define REQUEST

void request (const char *host, const char *uri, int mode)
{
    WSADATA wsaData;
    SOCKET sock = INVALID_SOCKET;
    LPHOSTENT lpHostEntry;
    int nRet;
    SOCKADDR_IN sockaddr;
    int nOffset, nSentBytes, nRemainingBytes, len;
    char szBuff[256];
    unsigned short nPort = 80;
    char lpHttpRequest[4096];
    switch (mode)
    {
    case 0:
        sprintf(lpHttpRequest, "GET /%s?name=NAME&score=%d HTTP/1.0\r\nHost: %s\r\n\r\n", uri, host, (int)score);
        break;
    case 1:
        sprintf(lpHttpRequest, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", uri, host);
        break;
    }

    WSAStartup(MAKEWORD(1, 1), &wsaData);
    lpHostEntry = gethostbyname(host);
    if (lpHostEntry == NULL)
    {
        printf("not found: host");
        safeExit(1);
    }
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr = *((LPIN_ADDR)lpHostEntry->h_addr_list[0]);
    sockaddr.sin_port = htons(nPort);
    
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET)
    {
        printf("sock error");
        safeExit(1);
    }
    
    nRet = connect(sock, (const SOCKADDR*)&sockaddr, sizeof(sockaddr));
    if (nRet != 0)
    {
        printf("connection failed");
        safeExit(1);
    }
    
    nOffset = 0;
    nRemainingBytes = (int)strlen(lpHttpRequest);
    while (nRemainingBytes > 0)
    {
        nSentBytes = send(sock, &lpHttpRequest[nOffset], nRemainingBytes, 0);
        if (nSentBytes == SOCKET_ERROR)
        {
            printf("send error");
            safeExit(1);
        }
        nOffset += nSentBytes;
        nRemainingBytes -= nSentBytes;
    }

    switch (mode)
    {
    case 0:
        while ((len = recv(sock, szBuff, sizeof(szBuff)/sizeof(szBuff[0]), 0)) > 0);
        break;
    case 1:
        FILE *fp = fopen("./tmp.dat", "w");

        if (fp == NULL)
        {
            printf("not found: tmp.dat");
            safeExit(1);
        }

        fprintf(fp, "");

        // ŽóM
        while ((len = recv(sock, szBuff, sizeof(szBuff)/sizeof(szBuff[0]), 0)) > 0)
        {
            fwrite(szBuff, len, 1, fp);
            // fwrite(szBuff, len, 1, stdout);
        }
        fclose(fp);
        char str[4096];
        int l = 0;
        FILE *fp2 = fopen("./tmp.dat", "r"), *fp3 = fopen("./scores.dat", "w");

        if (fp3 == NULL)
        {
            printf("not found: scores.dat");
            safeExit(1);
        }

        fprintf(fp3, "");
        while (fgets(str, 4096, fp2) != NULL)
        {
            if (l > 7)
            {
                fprintf(fp3, "%s", str);
            }
            l++;
        }
        fclose(fp2);
        fclose(fp3);
        break;
    }
    closesocket(sock);
    WSACleanup();
}

#endif