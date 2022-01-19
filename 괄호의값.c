#include <stdio.h>
#include <string.h>

int main()
{
    char paren[50];
    int paren_len;
    int myStack[50], myTop; // myStack은 숫자와 괄호를 다 넣어야 하기 때문에 int형이어야 함 (숫자형으로)

    scanf("%s", paren);

    paren_len = strlen(paren);

    for (int i = 0; i < paren_len; i++)
    {

        //(((()()[][[]])))
        // 괄호를 음수로 종류별로 분류 ( : -1 , [ : -2

        // 경우의 수
        // 1.Stack의 맨 위에 여는 괄호가 있는 경우 or
        //   Stack에서 맨 위에 있는 여는 괄호를 pop
        //   Stack에다가 값을 push, ()--> 2 , [] --> 3

        // 2.Stack의 두번째 위에 여는괄호가 있는 경우
        //   Stack에서 맨 위에 있는 값과, 두번재 위에 있는 여는괄호를 모두 pop
        //   스택에다가 값을 push, (X) --> 2X [X] --> 3X
        // 3. Stack의 맨 위 값이 둘다 값이라면 합친다.(덧셈)

        if (paren[i] == '(' || paren[i] == '[')
        {
            if (paren[i] == '(')
                myStack[myTop++] = -1;
            else
                myStack[myTop++] = -2;
        }
        else
        {
            //닫는 괄호가 먼저 나오는 경우
            if (myTop == 0)
            {
                printf("0\n");
                return 0;
            }
            // 비어있지 않은 경우!
            if (myStack[myTop - 1] == -1 || myStack[myTop - 1] == -2)
            { //myTop이 0일 경우에 대한 예외처리
                //짝이 맞는 경우
                if (paren[i] == ')' && myStack[myTop - 1] == -1)
                {
                    myStack[--myTop] = 0;
                    myStack[myTop++] = 2;
                }
                else if (paren[i] == ']' && myStack[myTop - 1] == -2)
                {
                    myStack[--myTop] = 0;
                    myStack[myTop++] = 3;
                }
                //입력이 이상하면
                else
                {
                    printf("0\n");
                    return 0;
                }
            }
            // 맨위가 값이라면
            else
            {
                int myValue = myStack[myTop - 1];
                myStack[--myTop] = 0;
                if (paren[i] == ')' && myStack[myTop - 1] == -1)
                {
                    myStack[--myTop] = 0;
                    myStack[myTop++] = 2 * myValue;
                }
                else if (paren[i] == ']' && myStack[myTop - 1] == -2)
                {
                    myStack[--myTop] = 0;
                    myStack[myTop++] = 3 * myValue;
                }
                else
                {
                    printf("0\n");
                    return 0;
                }
            }
            // 두개의 숫자를 하나의 숫자로 만드는 부분
            if (myTop >= 2 && myStack[myTop - 1] > 0 && myStack[myTop - 2] > 0)
            { // Stack에 원소가 하나만 있을 수도 있으므로 예외처리 해야함
                myStack[myTop - 2] += myStack[myTop - 1];
                myStack[--myTop] = 0;
            }
        }
    }
    // 원래 값이 제대로 계산됐으면 myTop = 1
    //Stack에 하나밖에 없는데 안되는 경우 --> Ex: '(' 는 제외

    if (myTop == 1 && myStack[0] > 0)
        printf("%d\n", myStack[0]);
    else
        printf("0\n");

    return 0;
}