# GPO 031
# Ariadne Selena Romero Rivero 1957540
# José Javier Puerta Mariñez 2082918
#metodo de biseccion 
import matplotlib.pyplot as plt 
import numpy as np
from sympy import symbols
from sympy import lambdify
from sympy import sympify 

print("")
x = symbols('x') # x es una variable simbolica que se usara en nuestra funcion 
fn = sympify(input("Ingresa la función: ")) #define la funcion que nos interesa 
f = lambdify(x, fn)

#inicia las variables 
a = float(input("Dame el valor inicial de x1: ")) #ingresar valor inicial
b = float(input("Dame el valor inicial de xu: ")) #ingresar valor inicial 
crit = float(input("Dame el porcentaje de error: ")) #ingresar el porcentaje de error

while crit < 0:
    crit = float(input("El porcentaje debe ser positivo. Ingrese de nuevo: ")) 

i= 0 #iniciar el contador 
ea = 100 #iniciar la variable de error
x_anterior = 0  #iniciar la variable de x anterior 


#criterio incial para verificar si la solucion esta en el intervalo seleccionado 
if f(a) * f(b) < 0:
    #imprime encabezados de tabla
    print(" ")
    print("{:^60}".format("METODO DE BISECCION"))
    print("{:^10} {:^10} {:^10} {:^10} {:^10}".format("i","x1","xu","xr","ea(%)")) 

    while ea > crit:
        xr = (a + b) / 2
        
        if xr==0:
            break

        if f(xr) * f(a) < 0:
            b= xr
        
        else:
            a = xr

        ea = abs((xr - x_anterior)/ xr) * 100
        x_anterior = xr 


        #imprime valores de la tabla 
        print("{:^10} {:^10f} {:^10f} {:^10f} {:^10}".format(i, a, b, xr, round(ea, 9)))
        i = i + 1

 
    if ea==100:
        print("{:^10} {:^10f} {:^10f} {:^10f} {:^10}".format(i, a, b, xr, round(ea, 9)))

    print("")
    print("El valor de xr es", round(xr,9), "con un error de", round(ea,9),"%")
    #graficamos la funcion e indicamos el punto 

    xpts = np.linspace(-15,15) # Hasta que punto será graficado la grafica
    plt.plot(xpts,f(xpts)) # Trazar la función f(x) en función de los puntos generados
    plt.title("grafica de la funcion") #título de la gráfica
    plt.axhline(color="black") # linea y=0 de color negro
    plt.axvline(color="black") # linea x=0 de color negro
    plt.scatter(xr,0,c="red") # Coloca el punto xr (xr, 0) en la gráfica
    plt.annotate(round(xr,9), xy=(xr,0.5)) # Agregar un texto con el valor de xr
    plt.xlabel("x") # Nombre Eje x
    plt.ylabel("f(x)") # Nombre Eje "f(x)"
    plt.grid(True, which='both') # Habilita cuadrícula
    plt.ylim([-20,20]) # límites de la gráfica en el rango de -20 a 20
    plt.show() # Mostrar la gráfica


else: #f(a)*f(b) >=0
    #si no hay raiz  se seleccionan 2 raices en un intervalo 
    print("")
    print("la funcion no tiene una raiz en el intervalo de " + "x = "+ str(a) + ",  x =" + str(b))
    print("Ingresar otros valores inciales")

    #graficamos la funcion e indicamos el punto
    xpts = np.linspace(-15,15)
    plt.plot(xpts,f(xpts))
    plt.title("grafica de la funcion")
    plt.axhline(color="black")
    plt.axvline(color="black")
    plt.xlabel("x")
    plt.ylabel("f(x)")
    plt.grid(True, which='both')
    plt.ylim([-20,20])
    plt.show()
    
