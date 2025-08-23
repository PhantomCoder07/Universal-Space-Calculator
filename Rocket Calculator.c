#include <stdio.h>
#include <math.h>
double mass (double F, double ve)
{
    return F/ve;
}
double velocity (double ve, double mo, double mf)
{
    return ve*log(mo/mf);
}
double thrust (double m, double ve, double pe, double pa, double Ae)
{
    return (m*ve)+((pe-pa)*Ae);
}
double spec_imp (double v, double go)
{
    return v/go;
}
double mass_fuel (double mo, double mf)
{
    return mo-mf;
}
double burn_rate (double mo, double mf)
{
    return mo/mf;
}
int main()
{
    double v,ve,mo,mf,pe,pa,go,m,Ae,F;
    int n;
    FILE *fp;
    fp = fopen("History.txt","w");
    printf("---------------//Welcome to Rocket Calculator\\\\---------------\n\n");
    while (1)
    {
        printf("What do you want to calculate?\n");
        printf("1 - Rocket's Mass\n");
        printf("2 - Rocket's Velocity (V)\n");
        printf("3 - Rocket's Thrust (F)\n");
        printf("4 - Rocket's Specific Impulse (Isp)\n");
        printf("5 - Mass of Fuel\n");
        printf("6 - Fuel Burn Rate\n");
        printf("0 - If you want to exit\n");
        printf("----------------------------------------------------------------\n");
        printf("Enter the number of your choice: ");
        scanf("%d",&n);
        printf("----------------------------------------------------------------\n");
        switch (n)
        {
        case 0:
            printf("Thank you.\n");
            break;
        case 1:
            printf("Now give information according to your choice:\n");
            printf("Enter rocket's thrust (F)         : ");
            scanf("%lf",&F);
            printf("Enter rocket's effective velocity : ");
            scanf("%lf",&ve);
            printf("Rocket's Mass                     : %.2e kg\n",mass(F,ve));
            fprintf(fp,"Rocket's Mass             : %.2e kg\n",mass(F,ve));
            break;
        case 2:
            printf("Now give information according to your choice:\n");
            printf("Enter rocket's effective velocity : ");
            scanf("%lf",&ve);
            printf("Enter rocket's initial mass       : ");
            scanf("%lf",&mo);
            printf("Enter rocket's final mass         : ");
            scanf("%lf",&mf);
            printf("Rocket's Velocity                 : %.2e m/s\n",velocity(ve,mo,mf));
            fprintf(fp,"Rocket's Velocity         : %.2e m/s\n",velocity(ve,mo,mf));
            break;
        case 3:
            printf("Now give information according to your choice:\n");
            printf("Enter rocket's mass               : ");
            scanf("%lf",&m);
            printf("Enter rocket's effective velocity : ");
            scanf("%lf",&ve);
            printf("Enter exhaust pressure            : ");
            scanf("%lf",&pe);
            printf("Enter ambient pressure            : ");
            scanf("%lf",&pa);
            printf("Enter area of nozzle              : ");
            scanf("%lf",&Ae);
            printf("Rocket's Thrust                   : %.2e N\n",thrust(m,ve,pe,pa,Ae));
            fprintf(fp,"Rocket's Thrust           : %.2e N\n",thrust(m,ve,pe,pa,Ae));
            break;
        case 4:
            printf("Now give information according to your choice:\n");
            printf("Enter rocket's velocity (F) : ");
            scanf("%lf",&v);
            printf("Enter planet's gravity (g)  : ");
            scanf("%lf",&go);
            printf("Rocket's Specific Impulse   : %.2e\n",spec_imp(v,go));
            fprintf(fp,"Rocket's Specific Impulse : %.2e\n",spec_imp(v,go));
            break;
        case 5:
            printf("Now give information according to your choice:\n");
            printf("Enter rocket's initial mass : ");
            scanf("%lf",&mo);
            printf("Enter rocket's final mass   : ");
            scanf("%lf",&mf);
            printf("Mass of Fuel                : %.2e kg\n",mass_fuel(mo,mf));
            fprintf(fp,"Mass of Fuel              : %.2e kg\n",mass_fuel(mo,mf));
            break;
        case 6:
            printf("Now give information according to your choice:\n");
            printf("Enter rocket's initial mass : ");
            scanf("%lf",&mo);
            printf("Enter rocket's final mass   : ");
            scanf("%lf",&mf);
            printf("Fuel Burn Rate              : %.2e\n",burn_rate(mo,mf));
            fprintf(fp,"Fuel Burn Rate            : %.2e\n",burn_rate(mo,mf));
            break;
        default:
            printf("Wrong Entry\n");
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
    return 0;
}
