#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//Declaracion de la estructura Numero Complejo
typedef struct NComplejo{
    float real;
    float imaginaria;
}NC;

//Declaracion de funciones 
void Mandelbrot (NC *c, int I);
NC *cuadradoComplejo(NC *x);
NC *sumaComplejo(NC *r, NC *i);
float magnitudComplejo(NC *x);

int main(){
    NC *n = (NC*)malloc (sizeof(NC));
    const int ITERACIONES_MAXIMAS=60;
    
    //Ingreso de los valores del número complejo C
    cout << "Ingresa Numero complejo." << endl;
    cout <<"Parte real:";
    cin >> n->real;
    cout << "Parte imaginaria: ";
    cin >> n->imaginaria;
    
    //Ejecuacion de la funcion de Mendelbrot 
    Mandelbrot(n, ITERACIONES_MAXIMAS);
    //cout << "El numero complejo es:" << n->real << " " << n->imaginaria << endl;

}

//Funcion que realiza la operacion cuadratica de un numero complejo
NC *cuadradoComplejo(NC *x){
    NC *aux = (NC*)malloc (sizeof(NC));
    aux->real = (x->real * x->real) - (x->imaginaria * x->imaginaria);
    aux->imaginaria = 2 * x->real * x->imaginaria;
    return aux;
}

//Funcion que realiza la suma de dos numeros complejos 
NC *sumaComplejo(NC *r, NC *i){
    NC *aux = (NC*)malloc (sizeof(NC));
    aux->real = r->real + i->real;
    aux->imaginaria = r->imaginaria + i->imaginaria;
    return aux;
}

//Funcion que obtiene la magnitud de un numero complejo 
float magnitudComplejo(NC *x){
    float mag = x->real + x->imaginaria;
    return mag;
}

//Funcion que realiza las operaciones para el conjunto de Mendelbrot
void Mandelbrot(NC *c, int I){
    int i;

    //Z0 = C
    NC *Z = c;
    NC *Zn = (NC *)malloc(sizeof(NC));
    for (i = 1; i <= I; i++)
    {   
        //ZN = (Zn-1 * Zn-1) + C
        Zn = sumaComplejo(cuadradoComplejo(Z), c);
        Z = Zn;
        cout << i << " real: " << Zn->real << " img: " << Zn->imaginaria << endl;
        
        //Comprobacion de la magnitud de Zn < 2
        if (magnitudComplejo(Z) > 2)
        {
            cout << "El elemento no esta en el conjunto" << endl;
            return;
        }

        //Comprobacion de que el ciclo llego al final por lo tanto el elemento C esta en el conjunto
        if (i == I)
        {
            cout << "El elemento esta en el conjunto" << endl;
        }
    }
}