#include <stdio.h>
#define H 2.27e-18
double velocity (double d)
{
    return 70*d;
}
double dis (double v)
{
    return v/70;
}
int main()
{
    double v,d;
    int n;
    FILE *fp;
    fp = fopen("History.txt","w");
    printf("---------------//Welcome to Cosmic Calculator\\\\---------------\n\n");
    while (1)
    {
        printf("What do you want to know?\n");
        printf("1 - Recession Velocity\n");
        printf("2 - Distance of Galaxy\n");
        printf("3 - Age of Universe\n");
        printf("0 - If you want to exit\n");
        printf("Enter number of your choice: ");
        scanf("%d",&n);
        switch (n)
        {
        case 0:
            printf("Thank you.\n");
            break;
        case 1:
            printf("Now give information according to your choice:\n");
            printf("Enter distance between galaxy (Mpc) : ");
            scanf("%lf",&d);
            printf("The recession velocity              : %.2e km/s\n",velocity(d));
            fprintf(fp,"The recession velocity : %.2e km/s\n",velocity(d));
            break;
        case 2:
            printf("Now give information according to your choice:\n");
            printf("Enter recession velocity (km/s) : ");
            scanf("%lf",&v);
            printf("The distance of galaxy          : %.2e Mpc\n",dis(v));
            fprintf(fp,"The distance of galaxy : %.2e Mpc\n",dis(v));
            break;
        case 3:
            printf("Age of universe : %.2e h\n",(1/H)/3600);
            fprintf(fp,"Age of universe        : %.2e h\n",(1/H)/3600);
            break;
        default:
            printf("Wrong entry\n");
        }
        printf("----------------------------------------------------------------\n");
        if (n==0)
            break;
        printf("Do you want to calculate more?\n");
        printf("1 - Yes\n");
        printf("0 - No\n");
        printf("----------------------------------------------------------------\n");
        printf("Make your choice: ");
        scanf("%d",&n);
        printf("----------------------------------------------------------------\n");
        if (n==0)
        {
            printf("Thank you.\n");
            printf("----------------------------------------------------------------\n");
            break;
        }
        else
            continue;
    }
    fclose(fp);
    char ch;
    fp = fopen("History.txt","r");
    printf("Here's the History:\n");
    printf("----------------------------------------------------------------\n");
    while (!feof(fp))
    {
        ch = getc(fp);
        printf("%c",ch);
    }
    fclose(fp);
    return 0;
}
