char *gnl(int fd)
{
    char    *res;
    int     resindex;
    static int  bufferindex = 0;
    static char    buffer[BUFFER_SIZE];
    static int     bytes_read;

    while(1)
    {
        if(bufferindex == 0) //rien lu encore
        {
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            res = realloc(res, strlen(res), strlen(res) + bytes_read);
            if(bytes_read < 0)
                return NULL;
            if(bytes_read == 0)
            {
                if(resindex > 0) // jai incrementer lindex de mon  res et je ne lis plus rien
                    break ;
                else
                    return NULL
            }
       
        }
        while(buffer[bufferindex] || buffer[bufferindex] != '\n')
            res[resindex++] = buffer[bufferindex++];
        if(buffer[bufferindex] == '\n')
        {
            res[resindex++] = '\n';
            break ;
        }
         if(bytes_read < BUFFER_SIZE)
            break;
        bytes_read = 0;
    }
    
    res[resindex] = '\0';
    return res;
}