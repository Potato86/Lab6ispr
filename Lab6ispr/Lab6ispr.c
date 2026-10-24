#include <stdio.h>
#include <locale.h>

int is_leap_year(int year);
double calc_f(double x);
int minutes_to_noon(int hour, int minute);
int minutes_to_midnight(int hour, int minute);

int main() {
    setlocale(LC_CTYPE, "ru_RU.UTF-8");

    int year;
    printf("Задание 1\n");
    printf("Введите год: ");
    scanf("%d", &year);

    if (is_leap_year(year))
        printf("Год %d високосный\n", year);
    else
        printf("Год %d не високосный\n", year);

    double x, f;
    printf("\nЗадание 2\n");
    printf("Введите x: ");
    scanf("%lf", &x);

    f = calc_f(x);
    printf("F(%.2f) = %.2f\n", x, f);

    int hour, minute, to_noon, to_midnight;
    printf("\nЗадание 3\n");
    printf("Введите часы (0-24): ");
    scanf("%d", &hour);
    printf("Введите минуты (0-60): ");
    scanf("%d", &minute);

    to_noon = minutes_to_noon(hour, minute);
    to_midnight = minutes_to_midnight(hour, minute);

    if (to_noon < to_midnight)
        printf("До будущего полудня %d минут\n", to_noon);
    else
        printf("До будущей полуночи %d минут\n", to_midnight);

    return 0;
}

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

double calc_f(double x) {
    /* x = 0  -> F = 9
       x = 7  -> F = -12
       x = 8  -> F = 1 */
    return (x <= 7) ? (-3 * x + 9) : (1.0 / (x - 7));
}

int minutes_to_noon(int hour, int minute) {
    /* 11:00 -> 60
       13:00 -> 1380
       00:00 -> 720 */
    int now = hour * 60 + minute;
    if (now < 720)
        return 720 - now;
    else
        return 720 + 1440 - now;
}

int minutes_to_midnight(int hour, int minute) {
    /* 11:00 -> 780
       13:00 -> 660 */
    int now = hour * 60 + minute;
    return 1440 - now;
}