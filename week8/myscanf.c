#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*

 * %d %f %c %s \t

 * 5개의 키워드 구현하기

 * 문자열이 조금이라도 일치하지 않을 경우 return -1로 오류 출력해도 됨

 */

int vr_scanf(const char *format, void *a, void *b, void *c, void *d)

{

    char input_str[512]; // 임시 문자열

    // char* token;         // 문자열 파싱을 위한 포인터

    int index = 0; // 지정된 변수를 저장하기 위한 인덱스

    char *input_ptr_token = input_str; // input_str의 배열 이름을 주면 주소 첫번째값을 준것과 동일

    gets_s(input_str, sizeof(input_str));

    while (format[index])
    {
        if (format[index] == '%')
        {
            index++;
            char *next_input = NULL;
            switch (format[index])
            {
            case 'd':
            {
                int *int_ptr = (int *)a;                                  // a의 주소값 숫자를 int형 포인터로 형변환하여 int *int_ptr안에 넣음 문자열에서 a의 위치를 알려줌
                *int_ptr = (int)strtol(input_ptr_token, &next_input, 10); // 현재 처리중인 문자열의 시작포인터 전달,
                // 함수가 문자열을 처리한 후, 변환되지 않은 나머지 문자열의 시작 위치를 저장하는 포인터입니다. 이를 사용하여 다음 처리할 문자의 위치를 업데이트, 10진법
                if (input_ptr_token == next_input)
                {
                    return;
                } // strtol() 사용시 변환된 숫자가 없다면, 함수가 문자열을 처리하지 못한것이기에 나머지 문자열의 시작위치가 next_input에 저장되지 않음
                // return으로 함수를 끝냄

                break;
            }
            case 'c':
            {
                char *char_ptr = (char *)b; // void *b를 함수 인수로 받는 것은 a가 어떤 타입의 포인터든 받아들인다는것 의미,
                // char b;의 포인터를 받아 char* 형식으로 받음. 실제 데이터에 접근하기 전에 해당 포인터를 적절한 타입의 포인터로 캐스팅해야 함
                // 현재 char b의 위치를 가리기고 있는 포인터를 저장중

                *char_ptr = input_ptr_token[0];
                next_input = input_ptr_token + 1;

                break;
            }

            case 'f':
            {
                float *float_ptr = (float *)c;
                *float_ptr = strtof(input_ptr_token, &next_input);
                if (input_ptr_token == next_input)
                {
                    return;
                }
                break;
            }

            case 's':
            {
                char *str_ptr = (char *)d;
                next_input = strchr(input_ptr_token, ','); // 입력 문자열(input_ptr)에서 ',' 문자를 찾는데, 이는 문자열 구분자로 사용됩니다. 만약 찾으면 해당 위치를 next_input에 저장하고, 찾지 못하면 next_input는 NULL이 됨
                str_ptr[next_input - input_ptr_token] = '\0';
                if (next_input != NULL)
                {
                    strncpy(str_ptr, input_ptr_token, next_input - input_ptr_token); // 주소 41248 - 41240
                    str_ptr[next_input - input_ptr_token] = '\0';
                }
                else
                {
                    strcpy(str_ptr, input_ptr_token);
                    next_input = input_ptr_token + strlen(input_ptr_token);
                }
                break;
            }
            default:
                return;
            }
            input_ptr_token = next_input + strspn(next_input, " \t\n|");
        }
        else
        {
            if (*input_ptr_token != format[index])
            {
                return;
            }
            input_ptr_token++;
        }
        index++;
    }
}

int main()

{

    int a;

    char b;

    float c;

    char d[1024];

    printf("Enter values: ");
    my_function("%d%c%f%s", &a, &b, &c, d);

    printf("Values entered: %d %c %f %s\n", a, b, c, d);

    return 0;

    // printf("Enter values: ");

    // int result = vr_scanf("%d|%c %f,%s", &a, &b, &c, d);

    // if (result == 0)

    //     printf("Values entered: %d %c %f %s\n", a, b, c, d);

    // else

    //     printf("Error\n");

    // return 0;
}
