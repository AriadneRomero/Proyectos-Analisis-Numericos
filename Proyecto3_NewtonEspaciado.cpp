//Interpolación de Newton con datos igualmente espaciados

// GPO 031
//Ariadne Selena Romero Rivero #1957540
//José Javier Puerta Mariñez #2082918

#include <iostream>
#include <cmath> 
using namespace std;

float newton(int, float *, float *, float);

bool mismoEspaciado(int n, float x[]);

int main()
{
	int n;
    cout << "Ingrese la cantidad de puntos: ";
    cin >> n;
    
    while(n<=1){
    	cout << "La cantidad de puntos no es valida\n Ingrese 2 o mas puntos: ";
    	cin >> n;
	}
    

    float *x = new float[n];
    float *y = new float[n];
    float xi;
  
    for (int i = 0; i < n; ++i){
    	cout << "\nIngrese los valores de x" <<i<< ":";
    	cin >> x[i];
		
		cout << "Ingrese los valores de y" <<i<< ":";	
		cin >> y[i];
	}
	
	
	
    cout << "\nIngrese el valor a interpolar: ";
    cin >> xi;

    float yi = newton(n, x, y, xi);
    cout << "Valor interpolado: " << yi << endl;

    delete[] x;
    delete[] y;

    return 0;

}

bool mismoEspaciado(int n, float x[]) {
    float espaciado = x[1] - x[0];
    float margen = 1e-6; // Margen de tolerancia para las comparaciones de punto flotante
    
    if(espaciado==0){
    	return false;
	}

    for (int i = 2; i < n; ++i) {
        if (abs(x[i] - x[i - 1] - espaciado) > margen) {
            return false; // No tienen el mismo espaciado.
        }
    }
    
    return true; // Todos los puntos tienen el mismo espaciado 
}




//interpolacion de newton 
float newton(int n, float *x, float *y, float xi){
	
	float b[n][n];
	float xt;
	float yi;
	
	//inicia la tabla de diferecnias
	for( int i=0; i<n; i++)
	b[i][0] = y[i];
	
	
	cout << "\nEl valor de las constantes son: ";
	//calcula la tabla de diferencias
	for(int j=1; j<n;j++){
		for(int i=0; i<n-j;i++){
			b[i][j]=(b[i +1][j - 1]-b[i][j-1])/(x[i+j]-x[i]);
		
			if(i==0)
			cout << "\n\t C" << j << ":" << b[i][j] ;
		}
	}
	
	cout << "\n\n";
	
	//interpola con el polinomio
	xt=1;
	yi= b[0][0];
	for(int j=0; j<n-1; j++)
	{
		xt=xt*(xi-x[j]);
		yi=yi+b[0][j+1]*xt;
	}
		return yi;
	
}
