#include <stdio.h>
#include <math.h>
#include "point.h"

// Nama : Gyan Maiziko
// NIM : 18221008
// Deskripsi : Implementasi dari point.h

POINT MakePOINT(float X, float Y)
{
    POINT p;
    Absis(p) = X;
    Ordinat(p) = Y;
    return p;
}

void BacaPOINT(POINT *P)
{
    float absis;
    float ordinat;
    scanf("%f %f", &absis, &ordinat);
    *P = MakePOINT(absis, ordinat);
}
void TulisPOINT(POINT P)
{
    printf("(%2.f,%2.f)", Absis(P), Ordinat(P));
}

boolean EQ(POINT P1, POINT P2)
{
    return Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2);
}

boolean NEQ(POINT P1, POINT P2)
{
    return !EQ(P1, P2);
}

boolean IsOrigin(POINT P)
{
    return Absis(P) == 0 && Ordinat(P) == 0;
}

boolean IsOnSbX(POINT P)
{
    return Ordinat(P) == 0;
}
boolean IsOnSbY(POINT P)
{
    return Absis(P) == 0;
}

int Kuadran(POINT P)
{
    if (Absis(P) > 0)
    {
        if (Ordinat(P) > 0)
        {
            return 1;
        }
        else
        {
            return 4;
        }
    }
    else
    {
        if (Ordinat(P) > 0)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
}

POINT PlusDelta(POINT P, float deltaX, float deltaY)
{
    Absis(P) += deltaX;
    Ordinat(P) += deltaY;
    return P;
}
void Geser(POINT *P, float deltaX, float deltaY)
{
    *P = PlusDelta(*P, deltaX, deltaY);
}

float Jarak0(POINT P)
{
    return sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2));
}

float Panjang(POINT P1, POINT P2)
{
    return sqrt(pow(Absis(P1) - Absis(P2), 2) + pow(Ordinat(P1) - Ordinat(P2), 2));
}