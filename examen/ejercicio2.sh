#!/bin/bash

BASE_DIR="${1:-logs}"

mkdir -p "$BASE_DIR/app1" "$BASE_DIR/app2" "$BASE_DIR/app3"

cat > "$BASE_DIR/app1/error.log" <<'EOF'
2026-03-20 INFO Usuario autenticado
2026-03-20 ERROR Fallo en conexión a BD
2026-03-20 WARNING Memoria alta
EOF

cat > "$BASE_DIR/app1/access.log" <<'EOF'
2026-03-20 INFO Usuario autenticado
2026-03-20 ERROR Fallo en conexión a BD
2026-03-20 WARNING Memoria alta
EOF

cat > "$BASE_DIR/app2/debug.log" <<'EOF'
2026-03-20 INFO Usuario autenticado
2026-03-20 ERROR Fallo en conexión a BD
2026-03-20 WARNING Memoria alta
EOF

cat > "$BASE_DIR/app2/error.log" <<'EOF'
2026-03-20 INFO Usuario autenticado
2026-03-20 ERROR Fallo en conexión a BD
2026-03-20 WARNING Memoria alta
EOF

cat > "$BASE_DIR/app3/system.log" <<'EOF'
2026-03-20 INFO Usuario autenticado
2026-03-20 ERROR Fallo en conexión a BD
2026-03-20 WARNING Memoria alta
EOF

grep -RIn --include="*.log" "ERROR" "$BASE_DIR" > errores.txt
grep -RIl --include="*.log" "ERROR" "$BASE_DIR" | sort -u > errores_procesados.log

echo "Listo. Archivos generados:"
echo " - errores.txt"
echo " - errores_procesados.log"