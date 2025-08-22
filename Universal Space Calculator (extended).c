#include <stdio.h>
#include <math.h>
#define G 6.67e-11
#define C 3e8
#define Pi 3.14159
#define Si 5.67e-8
double volume (double R)
{
    return (4*Pi*R*R*R)/3;
}
double density (double M, double R)
{
    return M/volume(R);
}
double sur_grav (double M, double R)
{
    return (G*M)/(R*R);
}
double esc_valo (double M, double R)
{
    return sqrt((2*G*M)/R);
}
double poten_energy (double m, double M, double R)
{
    return -(G*M*m)/R;
}
double energy (double M, double R)
{
    return -(3.0/5.0)*(G*M*M)/R;
}
double orb_per (double MM, double OR)
{
    return 2*Pi*sqrt((OR*OR*OR)/(G*MM));
}
double time_dila (double V)
{
    return 1/sqrt(1-((V*V)/(C*C)));
}
double schw_radius (double M)
{
    return (2*G*M)/(C*C);
}
double luminosity (double R, double T)
{
    return 4*Pi*(R*R)*Si*(T*T*T*T);
}
int main()
{
    double m,MM,M,R,OR,T,V,SMA;
    int n=0;
    char s[20];
    printf("----------//Welcome to Universal Space Calculator\\\\----------\n\n");
    while (1)
    {
        printf("Enter Planet's name: ");
        scanf("%s",s);
        printf("What do you want to calculate about planet \"%s\"?\n",s);
        while (1)
        {
            printf("1 - Planet's Volume (V)\n");
            printf("2 - Planet's Density (d)\n");
            printf("3 - Planet's Surface Gravity (g)\n");
            printf("4 - Planet's Escape Velocity (Ve)\n");
            printf("5 - Planet's Gravitational Potential Energy\n");
            printf("6 - Planet's Gravitational Binding Energy\n");
            printf("7 - Planet's Orbital Period\n");
            printf("8 - Planet's Schwarzschild Radius\n");
            printf("9 - Planet's Luminosity\n");
            printf("0 - If you want to exit\n");
            printf("Enter number according to your choice: ");
            scanf("%d",&n);
            if (n>=0 && n<=9)
            {
                printf("Thanks for your choice\n");
                printf("-------------------------------------------------------------\n");
                if (n==1)
                {
                    printf("Now give information according to your choice:\n");
                    printf("Enter the planet's radius (m): ");
                    scanf("%lf",&R);
                    printf("Planet's volume : %.2e m^3\n",volume(R));
                }
                else if (n==2)
                {
                    printf("Now give information according to your choice:\n");
                    printf("Enter the planet's mass (kg) : ");
                    scanf("%lf",&M);
                    printf("Enter the planet's radius (m): ");
                    scanf("%lf",&R);
                    printf("Planet's density : %.2e kg/m^3\n",density(M,R));
                }
                else if (n==3)
                {
                    printf("Now give information according to your choice:\n");
                    printf("Enter the planet's mass (kg) : ");
                    scanf("%lf",&M);
                    printf("Enter the planet's radius (m): ");
                    scanf("%lf",&R);
                    printf("Planet's surface gravity : %.2lf m/s^2\n",sur_grav(M,R));
                }
                else if (n==4)
                {
                    printf("Now give information according to your choice:\n");
                    printf("Enter the planet's mass (kg) : ");
                    scanf("%lf",&M);
                    printf("Enter the planet's radius (m): ");
                    scanf("%lf",&R);
                    printf("Planet's escape velocity : %.2lf km/s\n",esc_valo(M,R)/1000);
                }
                else if (n==5)
                {
                    printf("Now give information according to your choice:\n");
                    printf("Enter the planet's mass (kg) : ");
                    scanf("%lf",&M);
                    printf("Enter the planet's radius (m): ");
                    scanf("%lf",&R);
                    printf("Enter mass of the object (kg): ");
                    scanf("%lf",&m);
                    printf("Planet's gravitational potential energy : %.2e J\n",poten_energy(m,M,R));
                }
                else if (n==6)
                {
                    printf("Now give information according to your choice:\n");
                    printf("Enter the planet's mass (kg) : ");
                    scanf("%lf",&M);
                    printf("Enter the planet's radius (m): ");
                    scanf("%lf",&R);
                    printf("Planet's gravitational binding energy : %.2e J\n",energy(M,R));
                }
                else if (n==7)
                {
                    printf("Now give information according to your choice:\n");
                    printf("Enter mass of the star           : ");
                    scanf("%lf",&MM);
                    printf("Enter planet's orbital radius (m): ");
                    scanf("%lf",&OR);
                    printf("Planet's orbital period : %.2lf h\n",orb_per(MM,OR)/3600);
                }
                else if (n==8)
                {
                    printf("Now give information according to your choice:\n");
                    printf("Enter the planet's mass (kg) : ");
                    scanf("%lf",&M);
                    printf("Planet's schwarzschild radius : %.2e m\n",schw_radius(M));
                }
                else if (n==9)
                {
                    printf("Now give information according to your choice:\n");
                    printf("Enter the planet's radius (m): ");
                    scanf("%lf",&R);
                    printf("Enter surface temperature (K): ");
                    scanf("%lf",&T);
                    printf("Planet's luminosity : %.2e W\n",luminosity(R,T));
                }
                else if (n==0)
                {
                    printf("Thank you.\n");
                    break;
                }
            }
            else
            {
                printf("Wrong entry.\n");
                printf("-------------------------------------------------------------\n");
                printf("Choice carefully\n");
                continue;
            }
            printf("-------------------------------------------------------------\n");
            printf("Do you want to calculate more for planet \"%s\"?\n",s);
            printf("0 - If you want to continue\n");
            printf("1 - If you want to exit\n");
            printf("Make your choice: ");
            scanf("%d",&n);
            if (n==0)
            {
                printf("Thanks for your choice\n");
                continue;
            }
            else if (n==1)
            {
                printf("Thank you.\n");
                break;
            }
        }
        printf("\n-------------------------------------------------------------\n");
        printf("Do you want to calculate for another planet?\n");
        printf("0 - Yes\n");
        printf("1 - No\n");
        printf("Make your choice: ");
        scanf("%d",&n);
        if (n==0)
        {
            printf("Thanks for your choice\n");
            printf("-------------------------------------------------------------\n");
            continue;
        }
        else if (n==1)
        {
            printf("Thank you.\n");
            break;
        }
    }
    return 0;
}

