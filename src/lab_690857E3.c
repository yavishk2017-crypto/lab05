#include <stdio.h>
#include <string.h>
void copy(char *psource, char *ptarget, unsigned num_char)
{
    unsigned i = 0;
    while (i < num_char && *psource != '\0') 
    {
        *ptarget = *psource;
        psource++;
        ptarget++;
        i++;
    }
        if (i < num_char) 
        {
            *ptarget = '\0';
        }
}

void concatenate(char *psrc1, char *psrc2, char *ptarget, unsigned buffer_size)
{
    if (buffer_size == 0) 
    {
        return;
    }

    copy(psrc1, ptarget, buffer_size - 1);

    char *p = ptarget;
    unsigned len1 = 0;
    
    while (*p != '\0' && len1 < buffer_size - 1) 
    {
        p++;
        len1++;
    }

    unsigned space_left = buffer_size - len1;

    if (space_left > 1) 
    {
        copy(psrc2, p, space_left);
    }
}

#ifndef ___TEST___
int main(void)
{
    char buffer[100];
    char *source = "This is the first sentence.  ";
    char *target = "This is the second sentence.";

    concatenate(source, target, buffer, 70);

    printf("%s", buffer);
    return 0;
}
#endif
// DO NOT change the code above