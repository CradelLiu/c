//给定一个大写字母 要求用小写字母输出
void example_3_3() {
    char uppercase = 'A', lowercase;
    lowercase = uppercase + 32;
    printf("%c", lowercase); //以字符形式输出lowercase
    printf("%d", lowercase); //以ASCII码形式输出lowercase
}