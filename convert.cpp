#include<iostream>

using namespace std;

int converCelciusToFahrenheit(int celcius)
{

    return celcius * 9 / 5 + 32;
}

int main()
{
    int a = 1;
    printf("Enter Temperature in Celsius: ");
    scanf("%d", &a);
    printf("Temperature=%d",converCelciusToFahrenheit(a));
}

