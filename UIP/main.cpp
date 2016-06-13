//
//  main.cpp
//  UIP
//
//  Created by Miguel Cuellar on 3/17/16.
//  Copyright © 2016 Miguel Cuellar. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
    int n, x, y, i, j, a;
    float z,w,test,Yfinal;
    Yfinal=0;
    cout<<"Ingrese cantidad de pares a utilizar" << endl;
    cin>> n;
    
    float px[n],py[n],A[n][n],B[n][n],auxa[n],auxb[n];
    
    for (x = 0; x < n; x++){ // CREA 0 en aux
        auxa[x]=0;
        auxb[x]=0;
    }
    for (x = 0; x < n; x++){ // llena matriz identidad
        for(y = 0; y < n; y++){
            B[x][y]=0;
        }
        B[x][x]=1;
    }
    cout<<"Ingrese los valores de x | y:"<<endl;
    for (x = 0; x < n; x++){ //llena valores en x
        cout<< "x" <<x<<" :";
        cin>>px[x];
        if (px[0]==px[x]&&x!=0) {
            cout<<"X's repetidas"<<endl;
        }
        cout<< "y" <<x<<" :";
        cin>>py[x];
    }
    
    /*cout<<"Ingrese punto a evaluar:"<<endl;
    cin>>test;*/
    
    for (x = 0; x<n ; x++){
        for (y = 0; y<n ; y++){
            A[x][y]= pow(px[x],y);
        }
    }
    
    for (x = 0; x < n; x++){
        if (A[x][x] == 0){
            for (y = x; y < n ; y++){
                if (A[y][x] == 0){
                }
                else {
                    for (a = 0; a < n; a++){
                        auxa[a]=A[y][a];
                        auxb[a]=B[y][a];
                        A[y][a]=A[x][a];
                        B[y][a]=B[x][a];
                        A[x][a]=auxa[a];
                        B[x][a]=auxb[a];
                    }
                }
            }
            
        }
    }
    for (x = 0; x<n;x++){
        z=A[x][x];
        for (y = 0; y < n; y++){
            A[x][y]=A[x][y] / z; // CONSIGUE EL 1 EN LA DIAGONAL
            B[x][y] = B[x][y] / z;
        }
        for (i=0; i < n; i++){
            if(i == x){}
            else if (i != x){
                w = A[i][x];
                for (j = 0 ; j < n ; j++){
                    A[i][j]= (A[i][j])-(w * A[x][j]);
                    B[i][j]= (B[i][j])-(w * B[x][j]);
                }
            }
        }
    }
    cout<< "RESULTADOS"<<endl;
    cout<<"P"<<n-1<<"(x)= ";
    for (x = 0; x < n; x++){
        w = 0;
        for (y = 0; y < n; y++){
            w = w + (py[y] * B[x][y]);
        }
     /*   if (w!=w) {
            cout<<"No se puede calcular, x repetidas"<<endl;
            break;
        }*/
       // else
        cout<<""<<""<<w<<"x"<<x<<" + ";
        //Yfinal = Yfinal + (w*pow(test,x));
    }
    cout<<endl;

    
    return 0;
}
