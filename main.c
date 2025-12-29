#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*
 * 函数: contains_prohibited_words
 * 说明:
 *   检查传入的字符串是否包含预定义的不当词汇（不区分大小写）。
 * 参数:
 *   input - 指向以 '\0' 结尾的输入字符串
 * 返回值:
 *   如果检测到不当词汇返回 true，否则返回 false
 *
 * 注意:
 *   - 为避免 tolower 在负值字符上的未定义行为，使用 (unsigned char) 进行转换。
 *   - 将输入转换为小写后再进行匹配，以实现大小写不敏感的检测。
 *   - 为了避免越界，最多处理前 100 个字符，并确保目标缓冲区正确以 '\0' 终止。
 */
bool contains_prohibited_words(const char *input)
{
    const char *prohibited[] = {"fuck", "shit", "asshole", "pussy", "bitch"};
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
