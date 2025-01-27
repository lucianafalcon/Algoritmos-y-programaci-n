/* ARCHIVOS BINARIOS Y DE TEXTO - secuencial
                                - dinamico
                                - solo se agregan elem al final del archivo
                                - Nno se pueden modificar los elem existentes
--------------------------------------------------------------------------------------------------
    1- DECLARAR                             FILE *archivo;

    ----------------------------------------------------------------------------------------------
        ARCHIVO BINARIO: .dat
    2- ABRIR                                archivo = fopen("nombre.txt", "rb"/"rb+"/"wb"/"wb+"/"a");

        ARCHIVO DE TEXTO: .txt o .cvs 
    2- ABRIR                                archivo = fopen("nombre.txt", "r"/"r+"/"w"/"w+"/"a");
    ----------------------------------------------------------------------------------------------
        ARCHIVO BINARIO: .dat
    3- LEER                                 fread(&registro, sizeof(registro),1, archivo);

       ESCRIBIR                             fwrite(&registro, sizeof(registro), 1, archivo);

        ARCHIVO DE TEXTO: .txt o .csv
    3- LEER  - OPCION 1                     caracter = fgetc(archivo);          
             - OPCION 2                     fgets(cadena, MAX, archivo);          
             - OPCION 3                     fscanf(archivo, "%d", cadena);

       ESCRIBIR  - OPCION 1                 fputc(caracter, archivo);          //para leer cadena: caracter = getchar();
                 - OPCION 2                 fputs(cadena, archivo);            devuelve:  == 0, si se pudo grabar  o   !=0, si no se pudo grabar
                 - OPCION 3                 fprintf(archivo, "%d", numero);    devuelve: la cantidad de caracteres que grabo en el archivo
    
    ------------------------------------------------------------------------------------------------
    4- CONTROL DE FIN DE ARCHIVO            while((feof) == 0) o  while (!feof)     devuelve: {0->false,  1->verdadero}         
                                            while (EOF != 0)                        devuelve: {0->cuando fin de archivo, otroValor->cuando no es fin de archivo}

    ------------------------------------------------------------------------------------------------
    5- CIERRE                               fclose(archivo);

----------------------------------------------------------------------------------------------------
____________________________[  caracter = getchar();   ]______________________________
- la funcion GETCHAR sirve para leer. 
- lo que hace es detener la ejecucion del programa y espera a que el user teclee algo.
--------------------------------------------------------------------------------------*/