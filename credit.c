#include<stdio.h>
#include<cs50.h>

int main(void)
{
    long n = get_long("Number: ");
    long a = n % 100;
    long second = a / 10;
    long b = n % 10000;
    long fourth = b / 1000;
    long c = n % 1000000;
    long sixth = c / 100000;
    long d = n % 100000000;
    long eight = d / 10000000;
    long e = n % 10000000000;
    long tenth = e / 1000000000;
    long f = n % 1000000000000;
    long twelfth = f / 100000000000;
    long g = n % 100000000000000;
    long forteenth = g / 10000000000000;
    long h = n % 10000000000000000;
    long sixteenth = h / 1000000000000000;

     int i = second * 2;
    int j = fourth * 2;
    int k = sixth * 2;
    int l = eight * 2;
    int m = tenth * 2;
    int nn = twelfth * 2;
    int o = forteenth * 2;
    int p = sixteenth * 2;

    int q = i % 100;
    int ka = q / 10;
    int r = j % 100;
    int kha = r / 10;
    int s = k % 100;
    int ga = s / 10;
    int t = l % 100;
    int gha = t / 10;
    int u = m % 100;
    int cha = u / 10;
    int v = nn % 100;
    int chha = v / 10;
    int w = o % 100;
    int ja = w / 10;
    int x = p % 100;
    int jha = x / 10;

    int aa = i % 10;
    int bb = j % 10;
    int cc = k % 10;
    int dd = l % 10;
    int ee = m % 10;
    int ff = nn % 10;
    int gg = o % 10;
    int hh = p % 10;

    int sum = ka + kha + ga + gha + cha + chha + ja + jha + aa + bb + cc + dd + ee + ff + gg + hh;

    long first = n % 10;
    long bbb = n % 1000;
    long third = bbb / 100;
    long ccc = n % 100000;
    long fifth = ccc / 10000;
    long ddd = n % 10000000;
    long seventh = ddd / 1000000;
    long eee = n % 1000000000;
    long ninth = eee / 100000000;
    long fff = n % 100000000000;
    long eleventh = fff / 10000000000;
    long ggg = n % 10000000000000;
    long thirteenth = ggg / 1000000000000;
    long hhh = n % 1000000000000000;
    long fifteenth = hhh / 100000000000000;

    int checksum = first + third + fifth + seventh + ninth + eleventh + thirteenth + fifteenth + sum;
    int final = checksum % 10;
    if(final == 0)
    {
        if((forteenth==4 && sixteenth ==0 && fifteenth==3) || (forteenth==7 && sixteenth ==0 && fifteenth==3))
        {
            printf("AMEX\n");
        }
        else if((sixteenth == 5 && fifteenth == 1) || (sixteenth == 5 && fifteenth == 2) || (sixteenth == 5 && fifteenth == 3) || (sixteenth == 5 && fifteenth == 4) || (sixteenth == 5 && fifteenth == 5) || (sixteenth == 2 && fifteenth == 2 && forteenth == 2))
        {
            printf("MASTERCARD\n");
        }
        else if((sixteenth==0 && fifteenth==0 && forteenth==0 && thirteenth==4) || sixteenth==4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}