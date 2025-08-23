#include <stdio.h>
#include <math.h>
#define G 6.67e-11
#define Pi 3.14159
#define T 86164
double velocity (double M, double R, double r)
{
    return sqrt((G*M)/(R+r));
}
double period (double M, double R, double r)
{
    double H=R+r;
    return (2*Pi)*sqrt((H*H*H)/(G*M));
}
double geo (double M, double R)
{
    return cbrt((G*M*T*T)/(4*Pi*Pi))-R;
}
double energy (double M, double R, double r)
{
    return (G*M)/(2*(R+r));
}
int main()
{
    double M,R,r;
    int n;
    FILE *fp;
    fp = fopen("History.txt","w");
    printf("---------------//Welcome to Satellite Calculator\\\\---------------\n\n");
    while (1)
    {
        printf("What do you want to calculate?\n");
        printf("1 - Satellite's Orbital Velocity\n");
        printf("2 - Satellite's Orbital Period\n");
        printf("3 - Radius of GEO\n");
        printf("4 - Energy of Orbit\n");
        printf("0 - If you want to exit\n");
        printf("-------------------------------------------------------------------\n");
        printf("Enter number of your choice: ");
        scanf("%d",&n);
        printf("-------------------------------------------------------------------\n");
        switch (n)
        {
        case 0:
            printf("Thank you.\n");
            break;
        case 1:
            printf("Now give information according to your choice:\n");
            printf("Enter the planet's mass (kg)        : ");
            scanf("%lf",&M);
            printf("Enter the planet's radius (m)       : ");
            scanf("%lf",&R);
            printf("Enter the distance of satellite (m) : ");
            scanf("%lf",&r);
            printf("Satellite's orbital velocity        : %.2e m/s\n",velocity(M,R,r));
            fprintf(fp,"Satellite's orbital velocity : %.2e m/s\n",velocity(M,R,r));
            break;
        case 2:
            printf("Now give information according to your choice:\n");
            printf("Enter the planet's mass (kg)        : ");
            scanf("%lf",&M);
            printf("Enter the planet's radius (m)       : ");
            scanf("%lf",&R);
            printf("Enter the distance of satellite (m) : ");
            scanf("%lf",&r);
            printf("Satellite's orbital period          : %.2lf h\n",period(M,R,r)/3600);
            fprintf(fp,"Satellite's orbital period   : %.2lf h\n",period(M,R,r)/3600);
            break;
        case 3:
            printf("Now give information according to your choice:\n");
            printf("Enter the planet's mass (kg)  : ");
            scanf("%lf",&M);
            printf("Enter the planet's radius (m) : ");
            scanf("%lf",&R);
            printf("Radius of GEO                 : %.2e m\n",geo(M,R));
            fprintf(fp,"Radius of GEO                : %.2e m\n",geo(M,R));
            break;
        case 4:
            printf("Now give information according to your choice:\n");
            printf("Enter the planet's mass (kg)        : ");
            scanf("%lf",&M);
            printf("Enter the planet's radius (m)       : ");
            scanf("%lf",&R);
            printf("Enter the distance of satellite (m) : ");
            scanf("%lf",&r);
            printf("Energy of orbit                     : %.2e J\n",energy(M,R,r));
            fprintf(fp,"Energy of orbit              : %.2e J\n",energy(M,R,r));
            break;
        default:
            printf("Wrong entry\n");
            printf("-------------------------------------------------------------------\n");
            printf("Choice carefully\n");
        }
        printf("-------------------------------------------------------------------\n");
        if (n==0)
            break;
        printf("Do you want to calculate more?\n");
        printf("1 - Yes\n");
        printf("0 - No\n");
        printf("-------------------------------------------------------------------\n");
        printf("Make your choice: ");
        scanf("%d",&n);
        printf("-------------------------------------------------------------------\n");
        if (n==0)
        {
            printf("Thank you.\n");
            printf("-------------------------------------------------------------------\n");
            break;
        }
        else
            continue;
    }
    fclose(fp);
    char ch;
    fp = fopen("History.txt","r");
    printf("-------------------------------------------------------------------\n");
    printf("Here's the History:\n");
    while (!feof(fp))
    {
        ch=getc(fp);
        printf("%c",ch);
    }
    fclose(fp);
    return 0;
}

