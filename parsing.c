#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int is_delimiter(char c)
{
    if(c == 32 || (c >= 9 && c <= 13))
        return 1;
    return 0;
}

char *copy_word(char *str, int len)
{
    int i = 0;
    char *word=malloc(len + 1);
    if(!word)
        return NULL;
    while(i < len)
    {
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
    return word;
}

int count_word(char *str)
{
    int i = 0;
    int result = 0;
    int flag = 0;
    while(str[i])
    {
        if(is_delimiter(str[i]))
            flag = 0;
        else if(!flag)
        {
            result++;
            flag = 1;
        }
        i++;
    }
    return result;
}

char **split(char *str)
{
    int i = 0;
    int j = 0;
    int count = count_word(str);
    char **word=malloc(sizeof(char *) * (len + 1))
    if(!word)
        return NULL;
    while(str[i])
    {
        while(is_delimiter(str[i]))
            i++;
        if(str[i] == '\0')
            break;
        int start = i;
        while(str[i] && !is_delimiter(str[i]))
            i++;
        int len = i -start;
        word[j] = copy_word(&str[start], len);
        j++;
    }
    word[j] = NULL;
    return word;
}

// char **split(char *str)
// {
//     int i = 0;
//     int j = 0;
//     int count = count_word(str);
//     char **word_allocation=malloc(sizeof(char *) * (len + 1))
//     if(!word_allocation)
//         return NULL;
//     while(str[i])
//     {
//         while(is_delimiter(str[i]))
//             i++;
//         if(str[i] == '\0')
//             break;
//         int start = i;
//         while(str[i] && !is_delimiter(str[i]))
//             i++;
//         int len = i -start;
//         word_allocation[j] = copy_word_allocation(&str[start], len);
//         j++;
//     }
//     word_allocation[j] = NULL;
//     return word_allocation;
// }

int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;
    int sign = 1;
    while(is_delimiter(str[i]))
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 +str[i] -'0';
        i++;
    }
    return result *sign;
}

// int f_strln(char *str)
// {
//     int i = 0;
//     while(str[i])
//         i++;
//     return i;
// }


int f_strln(char **str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}
int main(int argc , char **argv)
{
    int i = 0;
    if(argc < 2)
    {
        write(1,"\n",1);
    }
    else
    {
        // int count = count_word(result[i]);
        char **result = ft_split(argv[1]);
        int len(result); //5
        int a[len - 1];
        // while(result[i])
        // {
            // ft_atoi(result[i]);
        //     printf("%d\n",a);
        //     i++;
        // }

        while(i <= len)
        {
            a[i] = ft_atoi(result[i]);
            printf("%d",a[i]);
            i++;
        }
        write(1,"\n",1);
    }
}
