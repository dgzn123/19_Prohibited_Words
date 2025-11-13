#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
bool contains_prohibited_words(const char *input)
{
    const char *prohibited[] = {"fuck", "shit", "asshole", "pussy"};
    int count = sizeof(prohibited) / sizeof(prohibited[0]);
    char lower_input[101];
    for (int i = 0; input[i] && i < 100; i++)
    {
        lower_input[i] = tolower(input[i]);
    }
    lower_input[100] = '\0';
    for (int i = 0; i < count; i++)
    {
        if (strstr(lower_input, prohibited[i]) != NULL)
        {
            return true;
        }
    }
    return false;
}
int main(void)
{
    char input[101];
    restart:
    printf("Please enter:");
    fgets(input, sizeof(input), stdin);
    if (contains_prohibited_words(input))
    {
        printf("How dare you, son of a bitch? Give you a chance and try again: \n");
        goto restart;
    }
    printf("Input accepted: %s", input);
    char judge;
    printf("Do you want to continue? (y/n): ");
    scanf(" %c", &judge);
    if (judge == 'y' || judge == 'Y')
    {
        getchar();
        goto restart;
    }
    return 0;
}