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
    char s[20];
    printf("Give Information about the Planet:\n");
    printf("-------------------------------------------------------------\n");
    printf("Enter the name               : ");
    scanf("%s",s);
    printf("Enter the mass (kg)          : ");
    scanf("%lf",&M);
    printf("Enter mass of the star (kg)\n(That it is orbiting)        : ");
    scanf("%lf",&MM);
    printf("Enter mass of the object (kg): ");
    scanf("%lf",&m);
    printf("Enter the radius (m)         : ");
    scanf("%lf",&R);
    printf("Enter orbital radius (m)     : ");
    scanf("%lf",&OR);
    printf("Enter the velocity (m/s)     : ");
    scanf("%lf",&V);
    printf("Enter surface temperature (K): ");
    scanf("%lf",&T);
    printf("-------------------------------------------------------------\n");
    printf("Calculated Information about the Planet : %s\n",s);
    printf("Planet's volume                         : %.2e m^3\n",volume(R));
    printf("Planet's density                        : %.2e kg/m^3\n",density(M,R));
    printf("Planet's surface gravity                : %.2lf m/s^2\n",sur_grav(M,R));
    printf("Planet's escape velocity                : %.2lf km/s\n",esc_valo(M,R)/1000);
    printf("Planet's gravitational potential energy : %.2e J\n",poten_energy(m,M,R));
    printf("Planet's gravitational binding energy   : %.2e J\n",energy(M,R));
    printf("Planet's orbital period                 : %.2lf h\n",orb_per(MM,OR)/3600);
    printf("Planet's schwarzschild radius           : %.2e m\n",schw_radius(M));
    printf("Planet's luminosity                     : %.2e W\n",luminosity(R,T));
    return 0;
}
