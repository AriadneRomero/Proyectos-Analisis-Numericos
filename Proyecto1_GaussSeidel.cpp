// GPO 031
//Ariadne Selena Romero Rivero #1957540
//José Javier Puerta Mariñez 2082918

#include<iostream>
#include<cmath>
using namespace std;

// Función para introducir los elementos de la matriz aumentada en fila
void introducirMatriz(double a[][17], int n) {
	int i, j;
	
    cout << "INTRODUZCA LOS ELEMENTOS DE LA MATRIZ AUMENTADA EN FILA: \n";
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            cout << "[" << i + 1 << "]" << "[" << j + 1 << "] = ";
            cin >> a[i][j];
        }
    }
}

// Función para imprimir la matriz
void imprimirMatriz(double a[][17], int n) {
	int i, j;
	
    cout << "\nTU MATRIZ ES LA SIGUIENTE:\n";
    for (i = 0; i < n; i++) {
        cout << "\n" << i + 1 << ". ";
        for (j = 0; j <= n; j++) {
            if (j == n) {
                cout << "= " << a[i][j];
            } else {
                cout << "|" << a[i][j] << "|";
            }
        }
    }
}

// Función para realizar el proceso de hacer las ecuaciones diagonalmente dominantes
void diagonalDominante(double a[][17], int n) {
	int i, j, k;
	
    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
        	
            if (abs(a[i][i]) < abs(a[k][i])) {
            	
                for (j = 0; j <= n; j++) {
                    double temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
    
}

// Función para comprobar si se puede aplicar el método de Gauss-Seidel
bool comprobarSeidel(double a[][17], int n) {
    int v = 0;
    for (int i = 0; i < n; ++i) {
        double suma = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                suma += abs(a[i][j]);
            }
            if (a[i][j] == 0) {
                v=1;
            }
        }
        if (abs(a[i][i]) < suma) {
            v=1;
        }
    }
    if (v == 1) {
        cout << "\n\nPara este sistema no se recomienda Gauss Seidel" << endl;
        cout << "Tome en cuenta que los valores pueden dar infinito o el resultado puede no ser correcto" << endl;
        return false;
    }
    return true;
}

// Función para realizar el método de Gauss-Seidel
void gaussSeidel(double a[][17], int n, double ps) {
    double x[16]; //variable que almacena los resultados de x1, x2, ... xn
    int count = 0; //Declaración del contador del número de iteraciones
    double ban=0; //Contador utilizado para determinar cuándo detener el ciclo.
	double y; //Almacena el valor anterior de cada variable x[i], esto se usa para el error aproximado
    int i, j;
    
    cout<<"\n\n";
    
    cout<<"ITERACION NO.";

    for(i=0;i<n;i++)            //Ciclo para mostrar en pantalla x1,x2,x3,xn.......
		cout<<"\t\t  x"<<i+1;

    cout<<"\n----------------------------------------------------------------------";

    do{    //Realizar iteraciones para calcular x1, x2, ... xn

        cout<<"\n"<<count+1<<".\t\t"; 

        for (i=0;i<n;i++)  //Ciclo que calcula los valores de x1,x2,x3 ...xn, Ciclo seidel
        {
            y=x[i];
            x[i]=a[i][n];

            for (j=0;j<n;j++)
            {
                if (j!=i)
                x[i]=x[i]-a[i][j]*x[j];
            }

            x[i]=x[i]/a[i][i];

            if (abs(x[i]-y)<=ps) //Compara los valores actuales con los ultimos valores arrojados por el calculo
				ban++;

            cout<<"|"<<x[i]<<"|"<<"\t\t\t"; 
        }

        cout<<"\n";             
        count++;    //Contador del número de iteraciones   

    }while(ban<n);  /*Si los valores de todas las variables no difieren de sus valores anteriores con un error mayor que
	                ps entonces el indicador debe ser n y por lo tanto detiene el bucle*/
    
    
    cout << "\nLA SOLUCION ES LA SIGUIENTE:\n";
    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << x[i] << endl;     
}

int main() {
    int n; //Declaración de variable del número de ecuaciones
    double a[16][17]; //Declaración de la matriz aumentada
	double ps; //Declaración del grado de precisión
	
    cout << "---------------------------------GAUSS SEIDEL-----------------------------------";
    cout << "\n-------------------------------------------------------------------------------" << endl;
    cout << "INTRODUZCA EL NUMERO DE ECUACIONES: ";
    cin >> n; // Número de ecuaciones
    
    introducirMatriz(a, n);
    
    cout << "\nINTRODUZA LA PRECISION HASTA LA CUAL DESEA LA SOLUCION EN DECIMALES:"<< endl;
    cin >> ps; /*El número del cual depende la finalización del programa al llegar con una solución aproximada con cierto grado de
				precisión después de cierto número de iteraciones*/
    
    system("cls");
    cout << "---------------------------------GAUSS SEIDEL-----------------------------------";
    cout << "\n-------------------------------------------------------------------------------" << endl;
    
    imprimirMatriz(a, n);
    
    diagonalDominante(a, n);
    
    cout << "\n\n----MATRIZ DESPUES DE APLICAR LA DIAGONAL DOMINANTE POR GAUSS SEIDEL---" << endl;
    
    imprimirMatriz(a, n);
    comprobarSeidel(a, n);
    
    /*if (comprobarSeidel(a, n)) {
        gaussSeidel(a, n, ps);
    }*/
    
    cout << "\n\n";
    system("PAUSE");
    
    gaussSeidel(a, n, ps);

    system("PAUSE");
    return 0;
}

