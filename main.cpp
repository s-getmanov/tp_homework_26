/*
Репозиторий к задаче:
https://github.com/s-getmanov/tp_homework_26.git
*/

#include <stdio.h>
#include <time.h>

int main()
{

    int day, month, year;

    //Проверять так проверять, проверим на ввод больше текущей.
    //Получим данные текущего времени для определения текущего года, месяца и дня.
    time_t _time = time(NULL);
    struct tm *current_time = localtime(&_time);

    int current_year = current_time->tm_year + 1900;
    int current_month = current_time->tm_mon + 1;
    int current_day = current_time->tm_mday; //

    //Мы пессимисты и считамем что больше 100 не живут :)
    int min_year = current_year - 100;

    printf("Введите данные вашей даты рождения - год, месяц, день.\n");

    bool input_success = false;

    //Будем добиваться от пользователя ввода корректных данных до победного конца или ввода 9999

    while (!input_success)
    {
        printf("Введите год в диапазоне от %i до %i (для выхода введите 9999): ", min_year, current_year);
        scanf("%i", &year);

        //Предусмотрим возможность выхода для уставших
        if (year == 9999)
        {
            return 0;
        }

        if (year < min_year || year > current_year)
        {
            printf("Вы ввели некорректный год, попробуйте еще раз (для выхода введите 9999).\n");
        }
        else
        {
            input_success = true;
        }
    };

    int max_month = 12;

    //В текущем году месяц не может быть больше текущего.
    if (year == current_year)
    {
        max_month = current_month;
    }

    input_success = false;

    while (!input_success)
    {
        printf("Введите месяц в диапазоне от 1 до %i (для выхода введите 9999): ", max_month);
        scanf("%i", &month);

        //Предусмотрим возможность выхода для уставших
        if (month == 9999)
        {
            return 0;
        }

        if (month < 1 || month > max_month)
        {
            printf("Вы ввели некорректный месяц, попробуйте еще раз (для выхода введите 9999).\n");
        }
        else
        {
            input_success = true;
        }
    };

    //Определение високосного года заранее, нужен для определения корректного дня в феврале.
    bool leap_year = year % 4 > 0;

    int max_day = 0;

    input_success = false;

    //В текущем году и в текущем месяце день не может быть больше текущего.
    if (year == current_year && month == current_month)
    {
        max_day = current_day;
    }
    else
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            max_day = 31;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            max_day = 30;
        }
        else if (month == 2 && leap_year)
        {
            max_day = 29;
        }
        else
        {
            max_day = 28;
        }
    }

    while (!input_success)
    {

        printf("Введите день в диапазоне от 1 до %i (для выхода введите 9999): ", max_day);
        scanf("%i", &day);

        //Предусмотрим возможность выхода для уставших
        if (day == 9999)
        {
            return 0;
        }

        if (day > 1 && day <= max_day)
        {
            input_success = true;
        }
        else
        {
            printf("Вы ввели некорректный день, попробуйте еще раз (для выхода введите 9999).\n");
        }
    }

    //Вывод определения високосного года

    if (leap_year)
    {
        printf("Вы родились не в високосном году\n");
    }
    else
    {
        printf("Вы родились в високосном году\n");
    };

    //Вывод года по восточному календарю

    int id;
    id = year % 12;

    switch (id)
    {
    case 0:
    {
        printf("Вы родились в год ОБЕЗЬЯНЫ.\n");
    }
    break;
    case 1:
    {
        printf("Вы родились в год ПЕТУХА.\n");
    }
    break;
    case 2:
    {
        printf("Вы родились в год СОБАКИ.\n");
    }
    break;
    case 3:
    {
        printf("Вы родились в год СВИНЬИ.\n");
    }
    break;
    case 4:
    {
        printf("Вы родились в год КРЫСЫ.\n");
    }
    break;
    case 5:
    {
        printf("Вы родились в год БЫКА.\n");
    }
    break;
    case 6:
    {
        printf("Вы родились в год ТИГРА.\n");
    }
    break;
    case 7:
    {
        printf("Вы родились в год КРОЛИКА.\n");
    }
    break;
    case 8:
    {
        printf("Вы родились в год ДРАКОНА.\n");
    }
    break;
    case 9:
    {
        printf("Вы родились в год ЗМЕИ.\n");
    }
    break;
    case 10:
    {
        printf("Вы родились в год ЛОШАДИ.\n");
    }
    break;
    case 11:
    {
        printf("Вы родились в год ОВЦЫ.\n");
    }
    break;

    default:
        break;
    }

    //Вывод знака зодиака

    if ((month == 3 && day > 20) || (month == 4 && day < 21))
    {
        printf("Ваш знак зодиака ОВЕН"); /* ОВЕН */
    }
    else if ((month == 4 && day > 20) || (month == 5 && day < 22))
    {
        printf("Ваш знак зодиака ТЕЛЕЦ");
    }
    else if ((month == 5 && day > 21) || (month == 6 && day < 22))
    {
        printf("Ваш знак зодиака БЛИЗНЕЦЫ");
    }
    else if ((month == 6 && day > 21) || (month == 7 && day < 23))
    {
        printf("Ваш знак зодиака РАК");
    }
    else if ((month == 7 && day > 22) || (month == 8 && day < 22))
    {
        printf("Ваш знак зодиака ЛЕВ");
    }
    else if ((month == 8 && day > 21) || (month == 9 && day < 24))
    {
        printf("Ваш знак зодиака ДЕВА");
    }
    else if ((month == 9 && day > 23) || (month == 10 && day < 24))
    {
        printf("Ваш знак зодиака ВЕСЫ");
    }
    else if ((month == 10 && day > 23) || (month == 11 && day < 23))
    {
        printf("Ваш знак зодиака СКОРПИОН");
    }
    else if ((month == 11 && day > 22) || (month == 12 && day < 23))
    {
        printf("Ваш знак зодиака СТРЕЛЕЦ");
    }
    else if ((month == 12 && day > 22) || (month == 1 && day < 21))
    {
        printf("Ваш знак зодиака КОЗЕРОГ");
    }
    else if ((month == 1 && day > 20) || (month == 2 && day < 20))
    {
        printf("Ваш знак зодиака ВОДОЛЕЙ");
    }
    else if ((month == 2 && day > 19) || (month == 3 && day < 21))
    {
        printf("Ваш знак зодиака РЫБЫ");
    }
}
