#include "../push_swap.h"

#include <stdlib.h>
#include <stdio.h>

static int count_word(char *str)
{
    int i = 0;
    int in_word = 0;
    int count = 0;
    while (str[i])
    {
        if (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
            in_word = 0;
        else if (!in_word)
        {
            count++;
            in_word = 1;
        }
        i++;
    }
    return count;
}

static char *copy_word(char *src, int len)
{
    int i = 0;
    char *word = (char *)malloc((len + 1) * sizeof(char));
    if (!word)
        return NULL;
    while (i < len)
    {
        word[i] = src[i];
        i++;
    }
    word[i] = '\0';
    return word;
}

char **ft_split(char *str)
{
    int i = 0;
    int j;
    int p = 0;

    int word_count = count_word(str);
    char **alloc_str = (char **)malloc((word_count + 1) * sizeof(char *));
    
    if (!alloc_str)
        return NULL;

    while (str[i])
    {
        while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
            i++;
        if (str[i] == '\0')
            break;
        j = i;
        while (str[i] && str[i] != 32 && (str[i] < 9 || str[i] > 13))
            i++;
        int len = i - j;
        alloc_str[p] = copy_word(&str[j], len);
        if (!alloc_str[p])
        {
            while (p >= 0)
                free(alloc_str[p--]);
            free(alloc_str);
            return NULL;
        }
        p++;
    }
    alloc_str[p] = NULL;
    return alloc_str;
}
