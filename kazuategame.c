#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

// 1024個の要素を持つchar型の配列に「String」という別名を命名
typedef char String[1024];

int main(void){
    printf("***数当てゲーム（レベル2）***\n3桁の数を当ててください!\n");
    // 答えを格納する配列を宣言
    int answer[3];
    // 入力値を格納する配列を宣言
    int input[3];

    // String型の変数「str」を宣言
    String str;

    // 乱数を生成する準備
    srand((unsigned)time(0UL));

    // 乱数の生成
    for (int i = 0; i < 3; i++)
    {
        // 答えに乱数を格納
        answer[i]=rand()%10;
    }

    // 数当てゲーム
    do{
        // 判定結果を格納する変数の初期化
        int hit=0;
        int brow=0;

        for (int i = 0; i <3; i++)
        {
            // 1桁ずつ予想を入力
            printf("%d桁目の予想を0~9の数字で入力してください:",i+1);
            scanf("%s",str);
            // 入力された値をint型に変換してinput[i]に格納
            input[i]=atoi(str);

            // 答えと入力値の位置と値の両方が一致しているか判定
            if (answer[i]==input[i])
            {
                hit+=1;
            }

            // 答えと入力値の値が一致しているか判定
            for (int j = 0; j < 3; j++)
            {
                if (answer[j]==input[i]&&i !=j)
                {
                    brow+=1;
                }
                
            }

        }
        // 結果を表示
        printf("%dヒット! %dブロー!",hit,brow);

        // すべて位置も値も一致した場合
        if (hit==3)
        {
            printf("正解です!");
            break;
        }else
        // それ以外の場合
        {
            // 入力値を格納する変数を宣言
            String str;
            // 続けるかどうかを格納する変数を宣言
            int next;
            // 続けるかどうかの確認と入力待ち
            printf("続けますか？(1:続ける 0:終了:");
            scanf("%s",str);
            // 入力値をint型に変換してnextに格納
            next=atoi(str);
            // 0(終了)の場合
            if (next==0)
            {
                // 正解を表示して終了する
                printf("正解は%d %d %dでした！\n",answer[0],answer[1],answer[2]);
                break;
            }
        }
    }while(true);
    return 0;
}