/*  ejercicio estructuras
Se pide un programa permita publicar productos a la venta por los alumnos de algoritmos 1. Se debe ingresar Código de producto nombre del producto,
Descripcion, grupo y precio.
1 Realizar una función que permita la carga de Productos.
2 Informar un listado de productos ordenados por Nombre del producto
3  Ingresar una palabra y realizar una búsqueda de productos que tengan dicha palabra en el nombre o descripción. 
4 Realizar un listado de los 10 productos  mas caros
5 Mostrar un listado ordenado por Código de producto
6 Ingresar un código y mostrar todos los datos del producto.


//7- Aplicar un aumento del 15% a los productos con precio mayor a 1000, 18% a los que estan entre 500 y 999 y 20% al resto.
//8- Emitir un listado que muestre la cantidad de productos por cada grupo. 
// 9 Mostrar numero de grupo y cantidad de productos. Usar estructuras auxiliares
// 10 Mostrar la cantidad de productos por Descripcion. Mostrar Descripcion y cantidad de productos. */

#include <stdio.h>
#include <String.h>

#define MAX_STRING 30
#define MAX_STRING_DESC 50
#define MAX 1000
typedef  char Tstring[MAX_STRING]
typedef  char TstringLargo[MAX_STRING]
typedef struct {
     int codigo;
     Tstring nombre ;
     TstringLargo descripcion ;
     int grupo ;
     float precio;
} TProducto;
typedef TProducto TTablaProductos[MAX];





void carga_productos(TTablaProductos Productos, int *ML)
{
    int i;
    char continuar;

    continuar = 's';
    i = 0;

    while (i < MAX && continuar == 's')
    {
        printf("ingrese nombre del producto: ");
        fgets(Productos[i].nombre, MAX_STRING, stdin);

        fflush(stdin);

        printf("ingrese descripcion del producto: ");
        fgets(Productos[i].descripcion, MAX_STRING_DESC, stdin);

        fflush(stdin);

        printf("ingrese grupo: ");
        scanf("%d", &Productos[i].grupo);

        printf("ingrese precio del producto: ");
        scanf("%d", &Productos[i].precio);


       printf("ingrese codigo del producto: ");
        scanf("%f", &Productos[i].codigo);

        printf("desea ingresar un nuevo producto? (s/n): ");
        scanf("%c", &continuar);

        fflush(stdin);
        
        i++;
    }

    *ML = i  ;
}


void ordenar_nombre(TTablaProductos Productos, int ML){     
    
    int i,j;
    TProducto  aux ;

    for (i=0<ML;i++)
    {
        for(j=1; j<ML-i; j++)
        {
            if (strcmp(Productos[j].nombre, Productos[j+1].nombre) > 0)
            {
                  aux = Producto[j+1] ;
                Productos[j+1]=Productos[i] ;
                Productos[i]=  aux ;         
            }
        }
    }

void mostrar_listado (TTablaProductos Productos, int ML){
    int i;
    printf("|    CODIGO    |     NOMBRE    |   PRODUCTO   |   GRUPO    |    PRECIO    |");
    for(i = 0; i < ML; i++){
      mostrar_producto( Producto[i] );
       
    }
}


void mostrar_producto (TProducto Producto) 
{
printf ("Nombre del Producto: %s", Producto.nombre);
printf("La descripcion es: %s",Producto.descripcion);
printf("El grupo del producto: %i",Producto.grupo);
printf("El precio del producto es: %f",Productoprecio);
printf("El codigo del producto es: %f",Producto.codigo);
} 
 
void Buscar_palabra (TTablaProductos Productos, int ML) 
{
int i, seguir;
  
TstringLargo  palabra ;
  
bool continuar;
  
continuar = true;
  
printf ("Ingrese una palabra a buscar: \n");
  
while (continuar)
    {
      fflush (stdin);
      scanf ("%s", palabra);
      fflush (stdin);
      
 
for (i = 0; i < ML; i++)
  {
      
if (strstr (palabra, Productos[i].nombre) >0 || strstr (palabra,Productos[i].descripcion) >0)
     
mostrar_producto (Productos[i]);
        
}
     
      
printf ("Queres seguir buscando? (1 para si, 0 para no\n") 
        fflush (stdin);
      
scanf ("%i", &seguir);
      
fflush (stdin);
      
if (seguir == 0)
        
        {
          
continuar = false;
   }     
}
   
int min(int a, int b)
{
    int resultado;

    if(a < b)
    {
        resultado = a;
    }
    else
    {
        resultado = b;
    }

    return resultado;
}

// ordena por burbujeo los productos
void productos_mas_caros(TTablaProductos Productos, int ML)
{
    int i, j;
    TProducto aux;
    for(i = 0; i < ML - 1; i++)
    {
        for(j = i + 1; j < ML; j++)
        {
            if(Productos[i].precio < Productos[j].precio)
            {
                aux = Productos[i];
                Productos[i] = Productos[j];
                Productos[j] = aux;
            }
        }
    }
}

void Ordenar_codigo(TTablaProductos Productos, int ML){
  int i, j;
  TProducto aux;
  for(i=1; i<ML; i++){
    for(j=0; j<ML-i; j++){ 
      if(Productos[j].codigo> Productos[j+1].codigo){ 
         aux =Productos[j];
         Productos[j] = Productos[j+1];
         Productos[j+1] = aux;
       }
    }
  }
}

int buscar_codigo(TTablaProductos Productos, int tamanio, int buscado)
{
  int inf, sup, mit;
  bool terminado;
  int posicion;
 
  // inicializaciones
  inf=0;
  sup=tamanio-1;
  terminado=false;

  while (!terminado)
  {
      if ((buscado > Productos[sup].codigo) || (buscado < Productos[inf].codigo))
      {
          terminado = true; // NO ESTA => FIN DE LA BUSQUEDA
          posicion = -1;
      }
      else
      {
          mit=(inf+sup)/2;
          if (Productos[mit].codigo == buscado)
          {
            terminado = true; // ENCONTRADO => FIN DE LA BUSQUEDA
            posicion = mit;
          }                
          else
            if(buscado > Productos[mit].codigo)
                inf= mit + 1;
            else
                sup= mit - 1;
      }        
  }

  return posicion;
}

void Producto_codigo (int Productos, int ML)
{
    int i, codigo, seguir, posicion;
    bool continuar;
    continuar = true;
    
    printf ("Ingrese un codigo a buscar: \n");
    while (continuar)
    
    {
      
fflush (stdin);
      
scanf ("%i", &codigo);
      
fflush (stdin);
      
    posicion = buscar_codigo(Productos, ML, codigo);
    
    if(posicion > -1)
    {
        mostrar_producto(Productos[posicion]);
    }
      else
    {
          
printf ("No hay resultados para la busqueda.\n");
        
}
      
printf ("Queres seguir buscando? (1 para si, 0 para no\n") 
        fflush (stdin);
      
scanf ("%i", &seguir);
      
fflush (stdin);
      
if (seguir == 0)
        
        {
          
continuar = false;
        
}
}
}

int main(){
TTablaProductos Productos;
int ML;
carga_productos(Productos, &ML);//1
ordenar_nombre(Productos, ML);//2
mostrar_listado(Productos, ML);//3
Buscar_palabra(Productos,ML);//4
productos_mas_caros(Productos, min(10,ML));//5
mostrar_listado(Productos, min(10,ML));
Ordenar_codigo (Productos, ML);//1,3
mostrar_Listado (Productos, ML);
Producto_codigo (Productos, ML);//2,4
Aumento_Precios(Productos,ML);
Cant_productos (Productos, ML, grupo);
return 0;
}


