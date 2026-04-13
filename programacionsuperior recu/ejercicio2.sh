#!/bin/bash

raiz="logs"

mkdir -p "$raiz"/app1
mkdir -p "$raiz"/app2
mkdir -p "$raiz"/app3

cat > "$raiz/app1/error.log" <<EOF
2026-03-20 INFO Usuario autenticado
2026-03-20 ERROR Fallo en conexión a BD
2026-03-20 WARNING Memoria alta
EOF

cat > "$raiz/app1/access.log" <<EOF
2026-03-20 INFO Usuario autenticado
2026-03-20 ERROR Fallo en conexión a BD
2026-03-20 WARNING Memoria alta
EOF

cat > "$raiz/app2/debug.log" <<EOF
2026-03-20 INFO Usuario autenticado
2026-03-20 ERROR Fallo en conexión a BD
2026-03-20 WARNING Memoria alta
EOF

cat > "$raiz/app2/error.log" <<EOF
2026-03-20 INFO Usuario autenticado
2026-03-20 ERROR Fallo en conexión a BD
2026-03-20 WARNING Memoria alta
EOF

cat > "$raiz/app3/system.log" <<EOF
2026-03-20 INFO Usuario autenticado
2026-03-20 ERROR Fallo en conexión a BD
2026-03-20 WARNING Memoria alta
EOF

> errores.txt
> errores_procesados.log

while IFS= read -r archivo; do
    
    if grep -q "ERROR" "$archivo"; then
        grep "ERROR" "$archivo" >> errores.txt
        echo "$archivo" >> errores_procesados.log
    fi
done < <(find "$raiz" -type f -name "*.log")

echo "Proceso finalizado."
echo "Resultado guardado en errores.txt"
echo "Nombres de archivos con errores guardados en errores_procesados.log"