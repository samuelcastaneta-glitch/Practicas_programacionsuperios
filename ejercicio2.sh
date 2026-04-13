#!/bin/bash

RUTA="/logs"

# Buscar archivos .log
archivos=$(find $RUTA -type f -name "*.log")

# Limpiar archivos previos
> errores.txt
> errores_procesados.log

for archivo in $archivos
do
    # Filtrar líneas con ERROR
    errores=$(grep "ERROR" "$archivo")

    if [ ! -z "$errores" ]; then
        echo "$errores" >> errores.txt
        echo "$archivo" >> errores_procesados.log
    fi
done

echo "Proceso completado"